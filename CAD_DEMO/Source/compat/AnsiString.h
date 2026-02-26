#pragma once
// AnsiString.h – Qt-based compatibility class replacing Borland's AnsiString.
// Provides the AnsiString API used throughout the project, backed by QString.

#include <QString>
#include <QByteArray>
#include <string>
#include <stdexcept>

// Extended is an 80-bit float in Borland; map to double for portability.
typedef double Extended;

class AnsiString {
public:
    // -----------------------------------------------------------------------
    // Constructors
    // -----------------------------------------------------------------------
    AnsiString() {}
    AnsiString(const char* s)     : d_(s ? QString::fromLatin1(s) : QString()) {}
    AnsiString(const std::string& s) : d_(QString::fromStdString(s)) {}
    AnsiString(const QString& s)  : d_(s) {}
    AnsiString(int n)             : d_(QString::number(n)) {}
    AnsiString(double v)          : d_(QString::number(v)) {}
    AnsiString(float v)           : d_(QString::number(static_cast<double>(v))) {}
    AnsiString(char c)            : d_(QString(QChar(c))) {}
    AnsiString(const AnsiString&) = default;
    AnsiString(AnsiString&&)      = default;
    AnsiString& operator=(const AnsiString&) = default;
    AnsiString& operator=(AnsiString&&)      = default;
    AnsiString& operator=(const char* s)     { d_ = s ? QString::fromLatin1(s) : QString(); return *this; }
    AnsiString& operator=(const QString& s)  { d_ = s; return *this; }

    // -----------------------------------------------------------------------
    // Conversion
    // -----------------------------------------------------------------------
    // Returns a pointer that is valid for the lifetime of this AnsiString object.
    const char* c_str() const {
        cache_ = d_.toLatin1();
        return cache_.constData();
    }
    operator QString() const { return d_; }
    std::string toStdString() const { return d_.toStdString(); }

    // -----------------------------------------------------------------------
    // Capacity / info
    // -----------------------------------------------------------------------
    int  Length()  const { return d_.length(); }
    bool IsEmpty() const { return d_.isEmpty(); }

    // -----------------------------------------------------------------------
    // Element access (1-based, Borland style)
    // -----------------------------------------------------------------------
    char operator[](int index) const {
        // Borland index is 1-based
        if (index < 1 || index > d_.length()) return '\0';
        return d_.at(index - 1).toLatin1();
    }

    // -----------------------------------------------------------------------
    // Concatenation
    // -----------------------------------------------------------------------
    AnsiString operator+(const AnsiString& rhs) const { return AnsiString(d_ + rhs.d_); }
    AnsiString operator+(const char* rhs)       const { return AnsiString(d_ + QString::fromLatin1(rhs)); }
    AnsiString operator+(char rhs)              const { return AnsiString(d_ + QChar(rhs)); }
    AnsiString& operator+=(const AnsiString& rhs) { d_ += rhs.d_; return *this; }
    AnsiString& operator+=(const char* rhs)       { d_ += QString::fromLatin1(rhs); return *this; }
    AnsiString& operator+=(char rhs)              { d_ += QChar(rhs); return *this; }

    // -----------------------------------------------------------------------
    // Comparison operators
    // -----------------------------------------------------------------------
    bool operator==(const AnsiString& o) const { return d_ == o.d_; }
    bool operator!=(const AnsiString& o) const { return d_ != o.d_; }
    bool operator< (const AnsiString& o) const { return d_ <  o.d_; }
    bool operator> (const AnsiString& o) const { return d_ >  o.d_; }
    bool operator<=(const AnsiString& o) const { return d_ <= o.d_; }
    bool operator>=(const AnsiString& o) const { return d_ >= o.d_; }

    bool operator==(const char* s) const { return d_ == QString::fromLatin1(s); }
    bool operator!=(const char* s) const { return d_ != QString::fromLatin1(s); }

    // -----------------------------------------------------------------------
    // Conversion methods
    // -----------------------------------------------------------------------
    int    ToInt()    const { return d_.toInt(); }
    double ToDouble() const { return d_.toDouble(); }
    float  ToFloat()  const { return d_.toFloat(); }

    // -----------------------------------------------------------------------
    // String operations
    // -----------------------------------------------------------------------
    // SubString: 1-based start position, len characters
    AnsiString SubString(int start, int len) const {
        if (start < 1) start = 1;
        return AnsiString(d_.mid(start - 1, len));
    }

    // Delete: remove 'count' characters starting at 1-based 'start'
    void Delete(int start, int count) {
        if (start < 1) return;
        d_.remove(start - 1, count);
    }

    // Insert: insert 'sub' before 1-based position 'pos'
    void Insert(const AnsiString& sub, int pos) {
        d_.insert(pos - 1, sub.d_);
    }

    // Pos: find sub-string; returns 1-based index, 0 if not found
    int Pos(const AnsiString& sub) const {
        int idx = d_.indexOf(sub.d_);
        return (idx < 0) ? 0 : idx + 1;
    }

    // AnsiCompare: case-sensitive comparison (returns 0 if equal, <0 if less, >0 if greater)
    int AnsiCompare(const AnsiString& other) const {
        return d_.compare(other.d_, Qt::CaseSensitive);
    }
    int AnsiCompareIC(const AnsiString& other) const {
        return d_.compare(other.d_, Qt::CaseInsensitive);
    }

    AnsiString UpperCase() const { return AnsiString(d_.toUpper()); }
    AnsiString LowerCase() const { return AnsiString(d_.toLower()); }
    AnsiString Trim()      const { return AnsiString(d_.trimmed()); }
    AnsiString TrimLeft()  const {
        QString tmp = d_;
        int i = 0;
        while (i < tmp.length() && tmp.at(i).isSpace()) ++i;
        return AnsiString(tmp.mid(i));
    }
    AnsiString TrimRight() const {
        QString tmp = d_;
        int i = tmp.length() - 1;
        while (i >= 0 && tmp.at(i).isSpace()) --i;
        return AnsiString(tmp.left(i + 1));
    }

    // -----------------------------------------------------------------------
    // Access underlying QString (useful when interoperating with Qt code)
    // -----------------------------------------------------------------------
    const QString& toQString() const { return d_; }
    QString&       toQString()       { return d_; }

    // -----------------------------------------------------------------------
    // Static helpers (Borland class methods)
    // -----------------------------------------------------------------------
    static AnsiString StringOfChar(char c, int count) {
        return AnsiString(QString(count, QChar(c)));
    }

private:
    QString          d_;
    mutable QByteArray cache_;
};

// ---------------------------------------------------------------------------
// Concatenation with char* on left
// ---------------------------------------------------------------------------
inline AnsiString operator+(const char* lhs, const AnsiString& rhs) {
    return AnsiString(QString::fromLatin1(lhs) + rhs.toQString());
}

// ---------------------------------------------------------------------------
// Global helper functions (mimic Borland SysUtils / System)
// ---------------------------------------------------------------------------

inline AnsiString IntToStr(int n)             { return AnsiString(n); }
inline AnsiString IntToStr(long n)            { return AnsiString(static_cast<int>(n)); }
inline AnsiString FloatToStr(double v)        { return AnsiString(v); }
inline AnsiString FloatToStr(float v)         { return AnsiString(v); }

inline int    StrToInt(const AnsiString& s)   { return s.ToInt(); }
inline double StrToFloat(const AnsiString& s) { return s.ToDouble(); }
inline double StrToDouble(const AnsiString& s){ return s.ToDouble(); }

inline AnsiString IntToHex(int value, int digits) {
    return AnsiString(QString("%1").arg(static_cast<uint>(value), digits, 16,
                                       QChar('0')).toUpper());
}

inline AnsiString AnsiUpperCase(const AnsiString& s) { return s.UpperCase(); }
inline AnsiString AnsiLowerCase(const AnsiString& s) { return s.LowerCase(); }

inline AnsiString Trim(const AnsiString& s)      { return s.Trim(); }
inline AnsiString TrimLeft(const AnsiString& s)  { return s.TrimLeft(); }
inline AnsiString TrimRight(const AnsiString& s) { return s.TrimRight(); }

// VCL-compatible string comparison
inline int AnsiCompareStr(const AnsiString& s1, const AnsiString& s2) {
    return s1.toQString().compare(s2.toQString());
}
inline int AnsiCompareText(const AnsiString& s1, const AnsiString& s2) {
    return s1.toQString().compare(s2.toQString(), Qt::CaseInsensitive);
}

// Format: use Qt's QString::asprintf via a free function
inline AnsiString Format(const char* fmt, ...) {
    char buf[4096];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    return AnsiString(buf);
}

// Borland-style NULL string check
inline bool EmptyStr(const AnsiString& s) { return s.IsEmpty(); }

// Borland string fill helper
inline AnsiString StringOfChar(char c, int count) {
    return AnsiString(QString(count, QChar(c)));
}
