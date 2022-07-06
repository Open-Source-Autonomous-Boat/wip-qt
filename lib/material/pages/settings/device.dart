import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:osab/db/db.dart';

class _DeviceGetCard extends StatefulWidget {
  const _DeviceGetCard({Key? key, required this.mID, required this.constraints})
      : super(key: key);

  final int mID;
  final BoxConstraints constraints;

  @override
  State<StatefulWidget> createState() => _DeviceGetCardState();
}

class _DeviceGetCardState extends State<_DeviceGetCard> {
  late final int mID = widget.mID;
  late final BoxConstraints constraints = widget.constraints;

  late final Future<DBData> mDeviceData;

  @override
  void initState() {
    super.initState();
    mDeviceData = _getData();
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
        future: mDeviceData,
        builder: ((BuildContext context, AsyncSnapshot<DBData> snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return Card(
              child: (constraints.maxWidth > 600)
                  ? const GridTile(
                      child: Text("WAITING"),
                    )
                  : const ListTile(
                      title: Text("WAITING"),
                    ),
            );
          } else if (snapshot.hasData &&
              snapshot.connectionState == ConnectionState.done) {
            final DBData data = snapshot.data!;
            final ElevatedButton editButton = ElevatedButton.icon(
                onPressed: () {
                  _showDialog(context, mID);
                },
                icon: const Icon(Icons.edit),
                label: const Text("Edit"));
            return Card(
              child: (constraints.maxWidth > 600)
                  ? GridTile(
                      header: ClipRRect(
                        borderRadius: BorderRadius.circular(8),
                        child: GridTileBar(
                          title: Text(data["name"].toString()),
                          backgroundColor:
                              Theme.of(context).colorScheme.primaryContainer,
                        ),
                      ),
                      footer: editButton,
                      child: const Center(child: Icon(Icons.directions_boat)),
                    )
                  : ListTile(
                      title: Text(data["name"].toString()),
                      leading: const Icon(Icons.directions_boat),
                      trailing: editButton,
                    ),
            );
          } else {
            return (constraints.maxWidth > 600)
                ? const GridTile(
                    header: GridTileBar(
                      title: Text("NULL DEVICE"),
                      backgroundColor: Colors.red,
                    ),
                    child: Icon(Icons.error),
                  )
                : const ListTile(
                    title: Text(
                      "NULL DEVICE",
                      style: TextStyle(backgroundColor: Colors.red),
                    ),
                  );
          }
        }));
  }

  Future<DBData> _getData() async {
    DeviceDB db = await DeviceDB.getInstance();
    await db
        .set({"id": 0, "name": "DEV-00", "uuid": 0.0, "date": "1970-01-01"});
    return await db.getItem<DBData>([mID.toString()]);
  }

  static void _showDialog(BuildContext context, int id) {
    showGeneralDialog(
        context: context,
        barrierDismissible: true,
        barrierLabel:
            MaterialLocalizations.of(context).modalBarrierDismissLabel,
        pageBuilder: ((context, animation, secondaryAnimation) {
          return Scaffold(
            appBar: AppBar(
              title: Text("Details - Device ID: $id"),
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
              children: const [
                ListTile(
                  leading: Icon(Icons.phone),
                  subtitle: TextField(
                    decoration: InputDecoration(border: OutlineInputBorder()),
                  ),
                ),
              ],
            ),
            floatingActionButton: FloatingActionButton(
              child: const Icon(Icons.save),
              onPressed: () {
                Navigator.of(context).pop();
              },
            ),
          );
        }));
  }
}

class AndroidSettingsDevice extends StatefulWidget {
  const AndroidSettingsDevice({super.key});

  @override
  State<StatefulWidget> createState() => _AndroidSettingsDevice();
}

class _AndroidSettingsDevice extends State<AndroidSettingsDevice> {
  late Future<int> mCount;

  @override
  void initState() {
    super.initState();
    mCount = _getCount();
  }

  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(
        builder: (BuildContext context, BoxConstraints constraints) {
      return Scaffold(
          appBar: AppBar(
            title: const Text("Device"),
            titleTextStyle: const TextStyle(fontWeight: FontWeight.bold),
          ),
          body: FutureBuilder(
              future: mCount,
              builder: ((context, snapshot) {
                List<Widget> children = [];
                if (snapshot.hasData &&
                    snapshot.connectionState == ConnectionState.done) {
                  int data = snapshot.data as int;
                  for (int i = 0; i < data; ++i) {
                    children.add(_DeviceGetCard(
                      mID: i,
                      constraints: constraints,
                    ));
                  }
                } else {
                  Widget child = const Text("NO DEVICE FOUND");
                  children.add((constraints.maxWidth > 600)
                      ? GridTile(child: child)
                      : ListTile(leading: child));
                }
                return (constraints.maxWidth > 600)
                    ? GridView.count(
                        padding: const EdgeInsets.all(5),
                        crossAxisCount: () {
                          if (constraints.maxWidth < 700) {
                            return 3;
                          } else if (constraints.maxWidth < 1000) {
                            return 4;
                          } else {
                            return 5;
                          }
                        }(),
                        children: children,
                      )
                    : ListView(
                        children: children,
                      );
              })),
          floatingActionButton: FutureBuilder(
              future: mCount,
              builder: ((BuildContext context, AsyncSnapshot<int> snapshot) {
                if (snapshot.hasData &&
                    snapshot.connectionState == ConnectionState.done) {
                  int data = snapshot.data!;
                  return FloatingActionButton(
                    onPressed: () {
                      _DeviceGetCardState._showDialog(context, data);
                    },
                    child: const Icon(Icons.add),
                  );
                }
                return FloatingActionButton(
                  onPressed: () {},
                  backgroundColor: Colors.red,
                  child: const Text("ERROR!"),
                );
              })));
    });
  }

  Future<int> _getCount() async {
    DeviceDB db = await DeviceDB.getInstance();
    return await db.getTotalItemCount();
  }
}
