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
  /* Dash {
	id: dash
	onDevnameChanged: {
	  dash_prop_dev_name.text = dash.devname
	}
  }  */
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
	  id: dash_prop_dev_name
	  text: Dash.devname
	  font.pixelSize: sett.font_size
	  //font.bold: true
	}
	/* Row 1 */
	Label {
	  text: "Process ID"
	  font.pixelSize: sett.font_size
	  font.bold: true
	}
	Label {
	  text: Dash.ppid
	  font.pixelSize: sett.font_size
	  //font.bold: true
	}
	Layout.fillWidth: true
  }
}
