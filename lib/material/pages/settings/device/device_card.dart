import 'package:flutter/material.dart';
import 'package:osab/db/db.dart';
import 'package:osab/material/pages/settings/device/edit_page.dart';

class DeviceGetCard extends StatefulWidget {
  const DeviceGetCard({Key? key, required this.mID, required this.constraints})
      : super(key: key);

  final int mID;
  final BoxConstraints constraints;

  @override
  State<StatefulWidget> createState() => _DeviceGetCard();
}

class _DeviceGetCard extends State<DeviceGetCard> {
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
            return const Card(
                child: GridTile(
              child: Text("WAITING"),
            ));
          } else if (snapshot.hasData &&
              snapshot.connectionState == ConnectionState.done) {
            final DBData data = snapshot.data!;
            final ElevatedButton editButton = ElevatedButton.icon(
                onPressed: () {
                  EditPage.showDialog(context, mID);
                },
                icon: const Icon(Icons.edit),
                label: const Text("Edit"));
            return Card(
                child: GridTile(
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
            ));
          } else {
            return const GridTile(
              header: GridTileBar(
                title: Text("NULL DEVICE"),
                backgroundColor: Colors.red,
              ),
              child: Icon(Icons.error),
            );
          }
        }));
  }

  Future<DBData> _getData() async {
    //DeviceDB db = await DeviceDB.getInstance();
    //return await db.getItem<DBData>([mID.toString()]);
    DBClass db = await DBInstances.devices();
    await db.set(
        DeviceDataValues(id: 0, name: "DEV-lol", uuid: 0.0, date: 000).asMap());
    DBData? data = await db.getItem(mID.toString());
    return data ?? {};
  }
}
