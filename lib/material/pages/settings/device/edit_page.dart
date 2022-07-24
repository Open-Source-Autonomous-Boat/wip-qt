import 'package:flutter/material.dart';

class EditPage extends StatefulWidget {
  const EditPage({Key? key, required this.id}) : super(key: key);

  @override
  State<StatefulWidget> createState() => _EditPage();
  static void showDialog(BuildContext context, int id) {
    showGeneralDialog(
        context: context,
        barrierDismissible: true,
        barrierLabel:
            MaterialLocalizations.of(context).modalBarrierDismissLabel,
        pageBuilder: ((context, animation, secondaryAnimation) {
          return EditPage(id: id);
        }));
  }

  final int id;
}

class _EditPage extends State<EditPage> {
  TextEditingController nameTextController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Details - Device ID: ${widget.id}"),
        actions: <Widget>[
          IconButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              icon: const Icon(
                Icons.delete,
              )),
          IconButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              icon: const Icon(Icons.save_as))
        ],
      ),
      body: ListView(
        children: [
          ListTile(
            leading: const Icon(Icons.edit),
            subtitle: TextField(
              controller: nameTextController,
              decoration: const InputDecoration(
                  border: OutlineInputBorder(), labelText: "Name"),
            ),
          ),
          const ListTile(
            leading: Icon(Icons.calendar_month),
            subtitle: TextField(
              decoration: InputDecoration(
                  border: OutlineInputBorder(), labelText: "Date"),
            ),
          ),
          ButtonBar(
            alignment: MainAxisAlignment.start,
            children: <Widget>[
              ElevatedButton(onPressed: () {}, child: const Text("Calibrate")),
              ElevatedButton(
                  onPressed: () {}, child: const Text("Set Default")),
            ],
          )
        ],
      ),
      floatingActionButton: FloatingActionButton(
        child: const Icon(Icons.save),
        onPressed: () {
          Navigator.of(context).pop();
        },
      ),
    );
  }
}
