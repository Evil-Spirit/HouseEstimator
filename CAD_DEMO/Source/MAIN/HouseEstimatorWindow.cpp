// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
// HouseEstimatorWindow.cpp – Qt main window implementation.

#include "HouseEstimatorWindow.h"

#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QMdiSubWindow>
#include <QSettings>
#include <QCloseEvent>

HouseEstimatorWindow::HouseEstimatorWindow(QWidget* parent)
    : QMainWindow(parent)
    , m_mdiArea(new QMdiArea(this))
    , m_statusLabel(new QLabel(this))
{
    setWindowTitle(tr("House Estimator"));
    resize(1200, 800);

    // MDI area as central widget
    m_mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_mdiArea->setViewMode(QMdiArea::SubWindowView);
    setCentralWidget(m_mdiArea);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
}

HouseEstimatorWindow::~HouseEstimatorWindow() = default;

// ---------------------------------------------------------------------------
// closeEvent
// ---------------------------------------------------------------------------
void HouseEstimatorWindow::closeEvent(QCloseEvent* event) {
    m_mdiArea->closeAllSubWindows();
    if (m_mdiArea->currentSubWindow()) {
        event->ignore();  // one of the sub-windows refused to close
    } else {
        event->accept();
    }
}

// ---------------------------------------------------------------------------
// Slots
// ---------------------------------------------------------------------------
void HouseEstimatorWindow::newFile() {
    statusBar()->showMessage(tr("New file – not yet implemented"), 3000);
}

void HouseEstimatorWindow::openFile() {
    const QString path = QFileDialog::getOpenFileName(
        this, tr("Open File"), QString(),
        tr("House Estimator files (*.home *.sps);;All files (*)"));
    if (!path.isEmpty()) {
        statusBar()->showMessage(tr("Opened: ") + path, 3000);
    }
}

void HouseEstimatorWindow::saveFile() {
    statusBar()->showMessage(tr("Save – not yet implemented"), 3000);
}

void HouseEstimatorWindow::saveFileAs() {
    const QString path = QFileDialog::getSaveFileName(
        this, tr("Save File As"), QString(),
        tr("House Estimator files (*.home *.sps);;All files (*)"));
    if (!path.isEmpty()) {
        statusBar()->showMessage(tr("Saved: ") + path, 3000);
    }
}

void HouseEstimatorWindow::closeFile() {
    if (QMdiSubWindow* sub = m_mdiArea->currentSubWindow())
        sub->close();
}

void HouseEstimatorWindow::exitApp() {
    close();
}

void HouseEstimatorWindow::about() {
    QMessageBox::about(this, tr("About House Estimator"),
        tr("<b>House Estimator</b><br>"
           "Migrated from Borland C++ Builder 6.0 to Qt.<br>"
           "Version 1.0.0"));
}

void HouseEstimatorWindow::aboutQt() {
    QApplication::aboutQt();
}

void HouseEstimatorWindow::tileWindows() {
    m_mdiArea->tileSubWindows();
}

void HouseEstimatorWindow::cascadeWindows() {
    m_mdiArea->cascadeSubWindows();
}

void HouseEstimatorWindow::closeAllWindows() {
    m_mdiArea->closeAllSubWindows();
}

// ---------------------------------------------------------------------------
// Setup helpers
// ---------------------------------------------------------------------------
void HouseEstimatorWindow::createActions() {
    m_newAction = new QAction(tr("&New"), this);
    m_newAction->setShortcut(QKeySequence::New);
    m_newAction->setStatusTip(tr("Create a new project"));
    connect(m_newAction, &QAction::triggered, this, &HouseEstimatorWindow::newFile);

    m_openAction = new QAction(tr("&Open..."), this);
    m_openAction->setShortcut(QKeySequence::Open);
    m_openAction->setStatusTip(tr("Open an existing project"));
    connect(m_openAction, &QAction::triggered, this, &HouseEstimatorWindow::openFile);

    m_saveAction = new QAction(tr("&Save"), this);
    m_saveAction->setShortcut(QKeySequence::Save);
    m_saveAction->setStatusTip(tr("Save the current project"));
    connect(m_saveAction, &QAction::triggered, this, &HouseEstimatorWindow::saveFile);

    m_saveAsAction = new QAction(tr("Save &As..."), this);
    m_saveAsAction->setShortcut(QKeySequence::SaveAs);
    connect(m_saveAsAction, &QAction::triggered, this, &HouseEstimatorWindow::saveFileAs);

    m_closeAction = new QAction(tr("&Close"), this);
    m_closeAction->setStatusTip(tr("Close the active sub-window"));
    connect(m_closeAction, &QAction::triggered, this, &HouseEstimatorWindow::closeFile);

    m_exitAction = new QAction(tr("E&xit"), this);
    m_exitAction->setShortcut(QKeySequence::Quit);
    m_exitAction->setStatusTip(tr("Exit the application"));
    connect(m_exitAction, &QAction::triggered, this, &HouseEstimatorWindow::exitApp);

    m_tileAction = new QAction(tr("&Tile"), this);
    m_tileAction->setStatusTip(tr("Tile the sub-windows"));
    connect(m_tileAction, &QAction::triggered, this, &HouseEstimatorWindow::tileWindows);

    m_cascadeAction = new QAction(tr("&Cascade"), this);
    m_cascadeAction->setStatusTip(tr("Cascade the sub-windows"));
    connect(m_cascadeAction, &QAction::triggered, this, &HouseEstimatorWindow::cascadeWindows);

    m_closeAllAction = new QAction(tr("Close &All"), this);
    m_closeAllAction->setStatusTip(tr("Close all sub-windows"));
    connect(m_closeAllAction, &QAction::triggered, this, &HouseEstimatorWindow::closeAllWindows);

    m_aboutAction = new QAction(tr("&About"), this);
    connect(m_aboutAction, &QAction::triggered, this, &HouseEstimatorWindow::about);

    m_aboutQtAction = new QAction(tr("About &Qt"), this);
    connect(m_aboutQtAction, &QAction::triggered, this, &HouseEstimatorWindow::aboutQt);
}

void HouseEstimatorWindow::createMenus() {
    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(m_newAction);
    m_fileMenu->addAction(m_openAction);
    m_fileMenu->addAction(m_saveAction);
    m_fileMenu->addAction(m_saveAsAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_closeAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAction);

    m_editMenu = menuBar()->addMenu(tr("&Edit"));
    // Edit actions will be populated during full migration

    m_viewMenu = menuBar()->addMenu(tr("&View"));
    // View actions will be populated during full migration

    m_windowMenu = menuBar()->addMenu(tr("&Window"));
    m_windowMenu->addAction(m_tileAction);
    m_windowMenu->addAction(m_cascadeAction);
    m_windowMenu->addSeparator();
    m_windowMenu->addAction(m_closeAllAction);

    m_helpMenu = menuBar()->addMenu(tr("&Help"));
    m_helpMenu->addAction(m_aboutAction);
    m_helpMenu->addAction(m_aboutQtAction);
}

void HouseEstimatorWindow::createToolBars() {
    m_mainToolBar = addToolBar(tr("Main"));
    m_mainToolBar->addAction(m_newAction);
    m_mainToolBar->addAction(m_openAction);
    m_mainToolBar->addAction(m_saveAction);
}

void HouseEstimatorWindow::createStatusBar() {
    m_statusLabel->setText(tr("Ready"));
    statusBar()->addWidget(m_statusLabel);
}
