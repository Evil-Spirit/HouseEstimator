#pragma once
// SUISkinEngine.hpp – Stub for the SUI Skin Engine UI theming library.
// The real SUISkinEngine is a proprietary VCL-based skin library.
// This stub provides empty class shells so the code compiles under Qt.

class TSUIManager {
public:
    TSUIManager()          {}
    virtual ~TSUIManager() {}

    void Active(bool)     {}
    bool Active() const   { return false; }
    void SkinFile(const char*) {}
    void ApplySkin()      {}
};

class TSUISkin {
public:
    TSUISkin()          {}
    virtual ~TSUISkin() {}
};

class TSUIScheme {
public:
    TSUIScheme()          {}
    virtual ~TSUIScheme() {}
};
