#pragma once
// VisIT 3D engine stubs for Qt/MSVC migration
// Replaces all VisClass.hpp, VisMath.hpp, VisComp.hpp, etc.
// These are minimal stub definitions that allow the code to compile;
// actual rendering functionality must be re-implemented.

// Include Qt global header early so Q_DECL_EXPORT etc. are defined
// before source files process their own COMMONAL_API macro definitions.
#include <QtGlobal>

#include <cstring>
#include <cmath>

// ---------------------------------------------------------------------------
// Basic geometry types used in Math headers (before full VCL/Qt headers arrive)
// ---------------------------------------------------------------------------
#ifndef TPOINT_DEFINED
#define TPOINT_DEFINED
struct TPoint {
    int x, y;
    TPoint() : x(0), y(0) {}
    TPoint(int _x, int _y) : x(_x), y(_y) {}
};
#endif

#ifndef TRECT_DEFINED
#define TRECT_DEFINED
struct TRect {
    int left, top, right, bottom;
    TRect() : left(0), top(0), right(0), bottom(0) {}
    TRect(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
    int Width()  const { return right - left; }
    int Height() const { return bottom - top; }
};
#endif

// ---------------------------------------------------------------------------
// Forward declarations
// ---------------------------------------------------------------------------
class TVisObject;
class TVisComp;
class TVisNode;
class TVisCustomObj;
class TVisPrimitiveObj;
class TVisRender;
class TVisView;
class TVisCustomView;
class TVisCamera;
class TVisLight;
class TVisLabel;
class TVisCanvas;
class TVisCanvasView;
class TVisTexture;
class TVisMaterial;
class TVisPolygon;
class TVisGeometry;
class TVisExchange;

// ---------------------------------------------------------------------------
// TVisVector – 3D vector with uppercase X, Y, Z (float)
// ---------------------------------------------------------------------------
struct TVisVector {
    float X, Y, Z;
    TVisVector() : X(0), Y(0), Z(0) {}
    TVisVector(float x, float y, float z) : X(x), Y(y), Z(z) {}
    void SetValues(float x, float y, float z) { X = x; Y = y; Z = z; }
    TVisVector& incX(float v) { X += v; return *this; }
    TVisVector& incY(float v) { Y += v; return *this; }
    TVisVector& incZ(float v) { Z += v; return *this; }
    TVisVector AsMathVector() const { return *this; }
};

// ---------------------------------------------------------------------------
// TVisMathVector – 3D math vector with lowercase x, y, z (float/double)
// ---------------------------------------------------------------------------
struct TVisMathVector {
    double x, y, z;
    double a; // optional angle/magnitude
    TVisMathVector() : x(0), y(0), z(0), a(0) {}
    TVisMathVector(double px, double py, double pz)
        : x(px), y(py), z(pz), a(0) {}
    TVisMathVector(double px, double py, double pz, double pa)
        : x(px), y(py), z(pz), a(pa) {}
    double length() const { return std::sqrt(x*x + y*y + z*z); }
    void normalize() {
        double len = length();
        if (len > 1e-12) { x /= len; y /= len; z /= len; }
    }
};

// Alias used in Bind/tolua generated code
typedef TVisMathVector TVisMathPoint;

// ---------------------------------------------------------------------------
// Helper function: create TVisMathVector from x,y,z (Borland VisIT API)
// ---------------------------------------------------------------------------
inline TVisMathVector ToVec(double x, double y, double z) {
    return TVisMathVector(x, y, z);
}
inline TVisVector ToVisVec(float x, float y, float z) {
    return TVisVector(x, y, z);
}

// ---------------------------------------------------------------------------
// TVisColor – RGBA color
// ---------------------------------------------------------------------------
struct TVisColor {
    float R, G, B, A;
    TVisColor() : R(1), G(1), B(1), A(1) {}
    TVisColor(float r, float g, float b, float a=1.0f)
        : R(r), G(g), B(b), A(a) {}
    float Alpha() const { return A; }
    void  Alpha(float a) { A = a; }
    float Color() const { return R; } // stub
};

// ---------------------------------------------------------------------------
// TVisTranslation, TVisTransform, TVisTransformation
// ---------------------------------------------------------------------------
struct TVisTranslation {
    float X, Y, Z;
    TVisTranslation() : X(0), Y(0), Z(0) {}
    TVisTranslation(float x, float y, float z) : X(x), Y(y), Z(z) {}
};

struct TVisTransform {
    float m[16];
    TVisTransform() { std::memset(m, 0, sizeof(m)); m[0]=m[5]=m[10]=m[15]=1.0f; }
};

enum TVisTransformationOrder { toSRT, toSTR, toRST, toRTS, toTSR, toTRS };

struct TVisTransformation {
    TVisVector   *Translation;
    TVisVector   *Rotation;
    TVisVector   *Scale;
    TVisTransformationOrder Order;
    bool         Empty;
    TVisTransformation()
        : Translation(nullptr), Rotation(nullptr), Scale(nullptr),
          Order(toSRT), Empty(true) {}
    void Execute() {}
};

// ---------------------------------------------------------------------------
// TVisTransparencyMode
// ---------------------------------------------------------------------------
enum TVisTransparencyMode { tmNone, tmBlend, tmAlphaTest };

// ---------------------------------------------------------------------------
// TVisAttributes – rendering attributes
// ---------------------------------------------------------------------------
enum TVisAttributes_Lighting    { vligOn, vligOff };
enum TVisAttributes_ShadeModel  { vshSmooth, vshFlat };
enum TVisAttributes_CullFace    { vcfNone, vcfBack, vcfFront };
enum TVisAttributes_PolygonMode { vpmFill, vpmLine, vpmPoint };
enum TVisAttributes_Antialiasing{ vaaOn, vaaOff };
enum TVisAttributes_Dithering   { vdiOn, vdiOff };
enum TVisAttributes_LightTwoSide{ vltsOn, vltsOff };
enum TVisAttributes_LineStipple { vlsOn, vlsOff };
enum TVisAttributes_PerspectiveCorrection { vpcOn, vpcOff };

struct TVisAttributes {
    TVisAttributes_Lighting      Lighting;
    TVisAttributes_ShadeModel    ShadeModel;
    TVisAttributes_CullFace      CullFace;
    TVisAttributes_PolygonMode   PolygonMode;
    TVisAttributes_Antialiasing  Antialiasing;
    TVisAttributes_Dithering     Dithering;
    TVisAttributes_LightTwoSide  LightTwoSide;
    TVisTransparencyMode         Transparency;
    float                        LineWidth;
    float                        PointSize;
    int                          LineStipple;
    float                        StippleScale;
    int                          StippleShift;
    TVisAttributes()
        : Lighting(vligOn), ShadeModel(vshSmooth), CullFace(vcfBack),
          PolygonMode(vpmFill), Antialiasing(vaaOn), Dithering(vdiOn),
          LightTwoSide(vltsOff), Transparency(tmNone),
          LineWidth(1.0f), PointSize(1.0f), LineStipple(0),
          StippleScale(1.0f), StippleShift(0) {}
};

// ---------------------------------------------------------------------------
// TVisMaterial
// ---------------------------------------------------------------------------
struct TVisMaterial {
    TVisColor *ColorAmbient_ptr;
    TVisColor *ColorDiffuse_ptr;
    TVisColor *ColorSpecular_ptr;
    TVisColor *ColorEmission_ptr;
    float      Shininess;
    int        Face;
    TVisMaterial()
        : ColorAmbient_ptr(nullptr), ColorDiffuse_ptr(nullptr),
          ColorSpecular_ptr(nullptr), ColorEmission_ptr(nullptr),
          Shininess(0), Face(0) {}
    virtual ~TVisMaterial() {}
};

// ---------------------------------------------------------------------------
// TVisTextureMode, TVisTextureFlags, TVisTexture
// ---------------------------------------------------------------------------
enum TVisTextureMode  { vtmReplace, vtmModulate, vtmDecal, vtmBlend };
enum TVisMagFilter    { vmfNearest, vmfLinear };
enum TVisMinFilter    { vmnNearest, vmnLinear };
enum TVisBufferType   { vbtRGB, vbtRGBA };

struct TVisTextureFlags {
    TVisTextureMode   Mode;
    float             ScaleX, ScaleY;
    float             ShiftX, ShiftY;
    float            *ParamVector_ptr;
    TVisTextureFlags()
        : Mode(vtmReplace), ScaleX(1), ScaleY(1),
          ShiftX(0), ShiftY(0), ParamVector_ptr(nullptr) {}
};

struct TVisTexture {
    TVisMagFilter   MagFilter;
    TVisMinFilter   MinFilter;
    TVisBufferType  Mode;
    TVisTextureFlags *Bitmap_ptr;
    TVisColor        *BlendColor_ptr;
    float             Alpha;
    TVisTexture()
        : MagFilter(vmfLinear), MinFilter(vmnLinear), Mode(vbtRGB),
          Bitmap_ptr(nullptr), BlendColor_ptr(nullptr), Alpha(1.0f) {}
    virtual ~TVisTexture() {}
    void AddMipMap()    {}
    void ClearMipMaps() {}
    void Invalidate()   {}
    void BitmapChange() {}
    void SetAlphaBitmap(void*) {}
    void SetMaskAlpha(float)   {}
};

// ---------------------------------------------------------------------------
// TVisDrawValues
// ---------------------------------------------------------------------------
struct TVisDrawValues {
    bool Visible;
    bool Selected;
    TVisDrawValues() : Visible(true), Selected(false) {}
};

// ---------------------------------------------------------------------------
// TVisObject – base VisIT object
// ---------------------------------------------------------------------------
class TVisObject {
public:
    bool Visible;
    TVisObject() : Visible(true) {}
    virtual ~TVisObject() {}
    virtual void Update()  {}
    virtual void Render()  {}
    virtual void Draw()    {}
};

// ---------------------------------------------------------------------------
// TVisComp – VisIT component base
// ---------------------------------------------------------------------------
class TVisComp : public TVisObject {
public:
    TVisComp()  {}
    virtual ~TVisComp() {}
};

// ---------------------------------------------------------------------------
// TVisNode – scene graph node
// ---------------------------------------------------------------------------
class TVisNode : public TVisComp {
public:
    TVisNode*  Parent;
    TVisNode() : Parent(nullptr) {}
    virtual ~TVisNode() {}
    virtual void AddChild(TVisNode*) {}
    virtual void RemoveChild(TVisNode*) {}
    virtual int  ChildCount() const { return 0; }
    virtual TVisNode* GetChild(int) { return nullptr; }
};

// ---------------------------------------------------------------------------
// TVisCustomNode
// ---------------------------------------------------------------------------
class TVisCustomNode : public TVisNode {
public:
    TVisCustomNode()  {}
    virtual ~TVisCustomNode() {}
};

// ---------------------------------------------------------------------------
// TVisCustomObj – custom VisIT object
// ---------------------------------------------------------------------------
class TVisCustomObj : public TVisNode {
public:
    TVisAttributes    *Attributes;
    TVisMaterial      *Material;
    TVisTexture       *Texture;
    TVisTransformation *Transformation;
    TVisDrawValues    *DrawValues;
    TVisCustomObj()
        : Attributes(nullptr), Material(nullptr),
          Texture(nullptr), Transformation(nullptr), DrawValues(nullptr) {}
    virtual ~TVisCustomObj() {}
};

// ---------------------------------------------------------------------------
// TVisPrimitiveObj – primitive VisIT object (has bounding box, etc.)
// ---------------------------------------------------------------------------
class TVisPrimitiveObj : public TVisCustomObj {
public:
    TVisVector BBoxMin;
    TVisVector BBoxMax;
    TVisPrimitiveObj() {}
    explicit TVisPrimitiveObj(void* /*unused*/) {}
    virtual ~TVisPrimitiveObj() {}
    virtual void Rebuild() {}
};

// ---------------------------------------------------------------------------
// TVisTransformed – transformed object
// ---------------------------------------------------------------------------
class TVisTransformed : public TVisPrimitiveObj {
public:
    TVisTransformed() {}
    virtual ~TVisTransformed() {}
};

// ---------------------------------------------------------------------------
// TVisDisc – disc primitive
// ---------------------------------------------------------------------------
class TVisDisc : public TVisPrimitiveObj {
public:
    float InnerRadius, OuterRadius;
    int   Slices, Loops;
    TVisDisc() : InnerRadius(0), OuterRadius(1), Slices(16), Loops(1) {}
    virtual ~TVisDisc() {}
};

// ---------------------------------------------------------------------------
// TVisBox – box primitive
// ---------------------------------------------------------------------------
class TVisBox : public TVisPrimitiveObj {
public:
    TVisVector HalfSize;
    TVisBox() {}
    virtual ~TVisBox() {}
};

// ---------------------------------------------------------------------------
// TVisGeometry – geometry object
// ---------------------------------------------------------------------------
class TVisGeometry : public TVisPrimitiveObj {
public:
    TVisGeometry() {}
    virtual ~TVisGeometry() {}
    virtual void Clear() {}
};

// ---------------------------------------------------------------------------
// TVisPolygon – polygon
// ---------------------------------------------------------------------------
class TVisPolygon : public TVisGeometry {
public:
    TVisPolygon() {}
    virtual ~TVisPolygon() {}
    virtual void AddVertex(float, float, float) {}
};

// ---------------------------------------------------------------------------
// TVisShape – shape (collection of geometry)
// ---------------------------------------------------------------------------
class TVisShape : public TVisPrimitiveObj {
public:
    TVisShape() {}
    virtual ~TVisShape() {}
};

// ---------------------------------------------------------------------------
// TVisCamera
// ---------------------------------------------------------------------------
class TVisCamera : public TVisNode {
public:
    TVisMathVector Position;
    TVisMathVector Target;
    TVisMathVector Up;
    float          FieldOfView;
    float          NearPlane;
    float          FarPlane;
    TVisCamera()
        : FieldOfView(60.0f), NearPlane(0.1f), FarPlane(1000.0f) {}
    virtual ~TVisCamera() {}
    virtual void Apply() {}
};

// ---------------------------------------------------------------------------
// TVisLight
// ---------------------------------------------------------------------------
enum TVisLightType { vltDirectional, vltPoint, vltSpot };

class TVisLight : public TVisNode {
public:
    TVisLightType LightType;
    TVisColor     Ambient;
    TVisColor     Diffuse;
    TVisColor     Specular;
    TVisMathVector Position;
    TVisMathVector Direction;
    bool          Enabled;
    TVisLight()
        : LightType(vltDirectional), Enabled(true) {}
    virtual ~TVisLight() {}
};

// ---------------------------------------------------------------------------
// TVisLabel
// ---------------------------------------------------------------------------
class TVisLabel : public TVisNode {
public:
    char  Text[256];
    float FontSize;
    TVisColor Color;
    TVisLabel() : FontSize(12.0f) { Text[0] = '\0'; }
    virtual ~TVisLabel() {}
    void SetText(const char* t) {
        if (t) {
            std::strncpy(Text, t, 255);
            Text[255] = '\0';
        }
    }
};

// ---------------------------------------------------------------------------
// TVisRender – base rendering object
// ---------------------------------------------------------------------------
class TVisRender : public TVisNode {
public:
    TVisRender()  {}
    virtual ~TVisRender() {}
    virtual void BeginRender() {}
    virtual void EndRender()   {}
    virtual void Render()      {}
    virtual void Invalidate()  {}
};

// ---------------------------------------------------------------------------
// TVisCustomView
// ---------------------------------------------------------------------------
class TVisCustomView : public TVisRender {
public:
    TVisCamera *Camera;
    TVisCustomView() : Camera(nullptr) {}
    virtual ~TVisCustomView() {}
    virtual void Resize(int, int) {}
};

// ---------------------------------------------------------------------------
// TVisView – 3D view/viewport
// ---------------------------------------------------------------------------
class TVisView : public TVisCustomView {
public:
    int Width, Height;
    TVisView() : Width(800), Height(600) {}
    virtual ~TVisView() {}
    virtual void SetViewport(int x, int y, int w, int h) {}
};

// ---------------------------------------------------------------------------
// TVisCanvas – canvas/viewport
// ---------------------------------------------------------------------------
class TVisCanvas : public TVisView {
public:
    TVisCanvas()  {}
    virtual ~TVisCanvas() {}
};

// ---------------------------------------------------------------------------
// TVisCanvasView – canvas view
// ---------------------------------------------------------------------------
class TVisCanvasView : public TVisCanvas {
public:
    TVisCanvasView()  {}
    virtual ~TVisCanvasView() {}
};

// ---------------------------------------------------------------------------
// TVisExchange – data exchange object
// ---------------------------------------------------------------------------
class TVisExchange : public TVisObject {
public:
    TVisExchange()  {}
    virtual ~TVisExchange() {}
    virtual bool Load(const char*) { return false; }
    virtual bool Save(const char*) { return false; }
};

// ---------------------------------------------------------------------------
// TVisColorAsMaterial
// ---------------------------------------------------------------------------
enum TVisColorAsMaterial { vcamNone, vcamAmbientDiffuse, vcamAmbient, vcamDiffuse };

// ---------------------------------------------------------------------------
// Misc enums used in binding code
// ---------------------------------------------------------------------------
enum TVisCullFace    { vculNone, vculBack, vculFront };
enum TVisLineStipple { vlstipOn, vlstipOff };
