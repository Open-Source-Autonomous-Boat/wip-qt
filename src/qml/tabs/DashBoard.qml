import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

import osab.xyz.DashBoard 1.0   // Fixes style issues bla bla bla
import "../snippets"
import "../settings"

ColumnLayout {
  id: root
  width: parent.width
  height: parent.height
  //Layout.topMargin: 20
  HeaderSnip{label_name: "Dashboard"}
  Dash {
                id: initial
  } 
  Settings {
      id: sett
  }
  GridLayout {
          columns: 2
          rows: 4
          height: root.height
          width: root.width
          /* Row 1 */
          Label {
                  text: "Device Name"
                  font.pixelSize: sett.font_size
                  font.bold: true
          }
          Label {
                  text: initial.GetPropDevName
                  font.pixelSize: sett.font_size
                  objectName: "dash_device_name"
                  //font.bold: true
          }
          /* Row 1 */
          Label {
                  text: "Process ID"
                  font.pixelSize: sett.font_size
                  font.bold: true
          }
          Label {
                  text: initial.GetPropPid
                  font.pixelSize: sett.font_size
                  objectName: "dash_pid_label"
                  //font.bold: true
          }
          Layout.fillWidth: true
  }
}
