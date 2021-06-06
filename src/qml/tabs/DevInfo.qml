import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import osab.xyz.DashBoard 1.0

import "../snippets"
import "../settings"

ColumnLayout {
  id: root
  Settings {
      id: sett
  }
  Dash {id: dash}
  HeaderSnip{label_name: "Device Information"}
  GridLayout {
      columns: 2
      rows: 2
      RowLayout {
          Label {
              font.pixelSize: sett.font_size
              text: "Device Information"
          }
          TextField {
              id: dev_name_field
              //objectName: dev_name_field_obj
              placeholderText: dash.GetPropDevName
              text: dash.GetPropDevName
          }
          Button {
              text: qsTr("Apply")
              onClicked: dash.GetPropDevName = dev_name_field.text
          }
      }
  }
}
