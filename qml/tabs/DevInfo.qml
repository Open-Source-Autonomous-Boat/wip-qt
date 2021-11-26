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
  ColumnLayout {
    Layout.leftMargin: 20
    Layout.rightMargin: 20
    RowLayout {
      Label {
        text: "Status"
      }
      Label {
        id: dis_stat_label
        property bool dis: true
        text: "Disconnected"//(dis) ? "Disconnected" : "Connected"
        font.bold: true
        color: (dis) ? "red" : "green"
      }
      Button {
        text: (dis_stat_label.dis) ? "Connect" : "Disconnect"
        visible: true //(dis_stat_label.dis) ? true : false
        onClicked: { dis_stat_label.dis = (dis_stat_label.dis) ? false : true }
      }
    }
    RowLayout {
      Label {
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
