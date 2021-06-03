import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

ColumnLayout {
  id: root
  width: parent.width
  height: parent.height
  property real font_size: Qt.application.font.pixelSize * 1.2
  property real header_font_size: Qt.application.font.pixelSize * 1.6
  //Layout.topMargin: 20
  Pane {
    width: parent.width
    height: parent.height
    palette.window: "#22000000"
    Label {
      text: "Dashboard"
      font.pixelSize: root.header_font_size
      font.bold: true
    }
    Layout.fillWidth: true
  }
  InitialWindow {
                id: initial
  } 
  GridLayout {
          columns: 2
          rows: 4
          height: root.height
          width: root.width
          /* Row 1 */
          Label {
                  text: "Device Name"
                  font.pixelSize: root.font_size
                  font.bold: true
          }
          Label {
                  text: "Unknown"
                  font.pixelSize: root.font_size
                  objectName: "dash_device_name"
                  //font.bold: true
          }
          /* Row 1 */
          Label {
                  text: "Process ID"
                  font.pixelSize: root.font_size
                  font.bold: true
          }
          Label {
                  text: initial.prop_pid
                  font.pixelSize: root.font_size
                  objectName: "dash_pid_label"
                  //font.bold: true
          }
          Layout.fillWidth: true
  }
}
