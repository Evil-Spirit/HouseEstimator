// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
#pragma once
// HouseEstimatorWindow.h – Qt main window replacing the Borland VCL TConfig MDI form.

#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>
#include <QLabel>
#include <QCloseEvent>
#include <QString>

class HouseEstimatorWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit HouseEstimatorWindow(QWidget* parent = nullptr);
    ~HouseEstimatorWindow() override;

    QMdiArea* mdiArea() const { return m_mdiArea; }

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void closeFile();
    void exitApp();

    void about();
    void aboutQt();

    void tileWindows();
    void cascadeWindows();
    void closeAllWindows();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

    // Central MDI area
    QMdiArea* m_mdiArea;

    // Menus
    QMenu* m_fileMenu;
    QMenu* m_editMenu;
    QMenu* m_viewMenu;
    QMenu* m_windowMenu;
    QMenu* m_helpMenu;

    // Toolbar
    QToolBar* m_mainToolBar;

    // File actions
    QAction* m_newAction;
    QAction* m_openAction;
    QAction* m_saveAction;
    QAction* m_saveAsAction;
    QAction* m_closeAction;
    QAction* m_exitAction;

    // Window actions
    QAction* m_tileAction;
    QAction* m_cascadeAction;
    QAction* m_closeAllAction;

    // Help actions
    QAction* m_aboutAction;
    QAction* m_aboutQtAction;

    // Status bar label
    QLabel* m_statusLabel;
};
