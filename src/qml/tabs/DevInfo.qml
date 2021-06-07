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
  /* I hate this */
  signal devinfo_change(string info)
  //Dash {id: dash}
  Settings {id: sett}
  HeaderSnip{label_name: "Device Information"}
  GridLayout {
      columns: 2
      rows: 2
      RowLayout {
          Label {
              font.pixelSize: sett.font_size
              text: "Device Name"
          }
          TextField {
              id: dev_name_field
              //objectName: dev_name_field_obj
              placeholderText: Dash.devname
              text: Dash.devname
              Layout.fillWidth: true
          }
          Button {
              text: qsTr("Apply")
              onClicked: {
				Dash.devname = dev_name_field.text
			  }
          }
      }
  }
}
