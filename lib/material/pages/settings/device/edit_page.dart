import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:osab/db/actions.dart';
import 'package:osab/material/pages/settings/device/edit_page/edit_page_name_field.dart';
import 'package:osab/material/pages/settings/device/edit_page/star_icon_button.dart';
import 'package:uuid/uuid.dart';

class EditPage extends StatefulWidget {
  const EditPage({Key? key, required this.id, this.firstTime = false})
      : super(key: key);

  @override
  State<StatefulWidget> createState() => _EditPage();
  static void showDialog(BuildContext context, int id,
      {Function(BuildContext context)? callback, bool firstTime = false}) {
    showGeneralDialog(
        context: context,
        barrierDismissible: true,
        barrierLabel:
            MaterialLocalizations.of(context).modalBarrierDismissLabel,
        pageBuilder: ((context, animation, secondaryAnimation) {
          return EditPage(
            id: id,
            firstTime: firstTime,
          );
        })).then((value) {
      if (callback != null) {
        if (kDebugMode) {
          print("Calling callback");
        }
        callback(context);
      }
    });
  }

  final int id;
  final bool firstTime;
}

class _EditPage extends State<EditPage> {
  TextEditingController nameTextController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    final EditPageNameField nameField = EditPageNameField(
      id: widget.id.toString(),
      controller: nameTextController,
    );
    return Scaffold(
      appBar: AppBar(
        title: Text("Details - Device ID: ${widget.id}"),
        actions: <Widget>[
          if (!widget.firstTime)
            IconButton(
                onPressed: () {
                  DBActions.rmDeviceId(widget.id.toString());
                  DBActions.resetFavoriteDevice(widget.id.toString());
                  Navigator.pop(context);
                  ScaffoldMessenger.of(context).showSnackBar(
                      SnackBar(content: Text("Deleted item id: ${widget.id}")));
                },
                icon: const Icon(Icons.delete)),
          if (!widget.firstTime)
            FavoriteButton(
                callback: () {
                  _ButtonActions.setDefault(widget.id);
                  setState(() {});
                },
                id: widget.id.toString())
        ],
      ),
      body: ListView(
        children: [
          nameField,
          ButtonBar(
            alignment: MainAxisAlignment.start,
            children: <Widget>[
              ElevatedButton(onPressed: () {}, child: const Text("Calibrate")),
              ElevatedButton(
                  onPressed: () {
                    _ButtonActions.setDefault(widget.id);
                  },
                  child: const Text("Set Default")),
            ],
          )
        ],
      ),
      floatingActionButton: FloatingActionButton(
        child: const Icon(Icons.save),
        onPressed: () {
          final String name = nameField.getText();
          if (name.isEmpty || name == "null") {
            if (kDebugMode) {
              print("Failed to get name");
            }
            ScaffoldMessenger.of(context)
                .showSnackBar(SnackBar(content: Text("Invalid name $name")));
            return;
          }
          var uuid = const Uuid().v5(Uuid.NAMESPACE_NIL, name);
          DBActions.setDevice(
              name: nameField.getText(), uuid: uuid, id: widget.id);
          ScaffoldMessenger.of(context)
              .showSnackBar(SnackBar(content: Text("Device $name saved")));
        },
      ),
    );
  }
}

class _ButtonActions {
  static setDefault(int aId) {
    DBActions.setFavoriteDevice(aId.toString());
  }
}
