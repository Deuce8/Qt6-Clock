#include <QApplication>
#include <QWindow>
#include <QMainWindow>
#include <QMargins>
#include <QSize>
#include <QFile>

#include <LayerShellQt/Shell>
#include <LayerShellQt/Window>

#include "central_widget.hpp"

int main(int argc, char **argv) {
    // Initialize Application
    LayerShellQt::Shell::useLayerShell();   // Ignore deprecated warnings, they are incorrect.
    QApplication app(argc, argv);

    // Application Details
    app.setOrganizationName("Qt6-Clock");
    app.setApplicationName("Qt6-Clock");
    
    // Custom qss style
    QFile style(":/assets/style.qss");
    if (style.open(QFile::ReadOnly))
        app.setStyleSheet(QLatin1String(style.readAll()));
    else
        qWarning() << "Failed to open style.qss";

    // Initialize MainWindow
    QMainWindow* main_window = new QMainWindow();
    main_window->setAttribute(Qt::WA_TranslucentBackground, true);
    main_window->setWindowFlag(Qt::FramelessWindowHint, true);

    // Content
    QWidget* central_widget = new CentralWidget(main_window);
    main_window->setCentralWidget(central_widget);

    // Final Window Setup
    main_window->resize(central_widget->size());
    main_window->show();
    
    // Layer Shell
    QWindow* window = main_window->windowHandle();
    if (LayerShellQt::Window *lsh = LayerShellQt::Window::get(window)) {
        lsh->setLayer(LayerShellQt::Window::LayerBackground);
        lsh->setAnchors(LayerShellQt::Window::AnchorBottom);

        if (argc > 1)
            lsh->setMargins(QMargins(0, 0, 0, std::stoi(argv[1])));
        
        lsh->setDesiredSize(central_widget->size());
    }

    // Run event loop
    return app.exec();
}