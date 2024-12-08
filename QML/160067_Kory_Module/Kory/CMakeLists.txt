qt_add_qml_module(PthinkSKoryUtil
    URI PthinkS.Kory.Two
    VERSION 1.0
    QML_FILES TestButton.qml
          HelloWorld.qml
          MyTextEdit.qml
          KoryMain.qml
    OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/KoryModule/bins
)
