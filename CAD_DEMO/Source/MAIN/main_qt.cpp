// main_qt.cpp – Qt application entry point replacing Borland's WinMain.
// This file provides the standard Qt main() that initialises QApplication,
// creates the main MDI window, and enters the event loop.

#include <QApplication>
#include <QSurfaceFormat>

#include "HouseEstimatorWindow.h"
#include "compat/vcl_qt.h"  // brings in TApplication / global Application ptr

// ---------------------------------------------------------------------------
// Global VCL-compat objects (declared extern in vcl_qt.h)
// ---------------------------------------------------------------------------
TApplication* Application = nullptr;
TScreen*      Screen      = nullptr;

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    // Set OpenGL surface format before QApplication is created
    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    fmt.setStencilBufferSize(8);
    fmt.setSamples(4);
    fmt.setVersion(3, 3);
    fmt.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(fmt);

    QApplication app(argc, argv);
    app.setApplicationName("HouseEstimator");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("HouseEstimator");

    // Initialise VCL-compat globals
    TApplication vcl_app;
    Application = &vcl_app;

    TScreen scr;
    Screen = &scr;

    // Create and show the main window
    HouseEstimatorWindow mainWin;
    vcl_app.MainForm = &mainWin;
    mainWin.show();

    return app.exec();
}
