import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

Pane {
  id: root
  width: parent.width
  height: parent.height
  palette.window: "#22000000"
  property string label_name: ""
  property real header_font_size: Qt.application.font.pixelSize * 1.6
  Label {
    text: root.label_name
    font.pixelSize: root.header_font_size
    font.bold: true
  }
  Layout.fillWidth: true
}
