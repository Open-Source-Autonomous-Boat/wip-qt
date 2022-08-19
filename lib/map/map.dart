import 'package:flutter/cupertino.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:flutter_map/plugin_api.dart';
import 'package:latlong2/latlong.dart';

class OSABMap extends StatefulWidget {
  const OSABMap({super.key});
  @override
  State<StatefulWidget> createState() => _OSABMap();
}

class _OSABMap extends State<OSABMap> {
  @override
  Widget build(BuildContext context) {
    return FlutterMap(
      options: MapOptions(center: LatLng(0, 0), zoom: 13),
      layers: [
        TileLayerOptions(
            urlTemplate: "https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png",
            subdomains: ['a', 'b', 'c'],
            attributionBuilder: ((context) =>
                const Text("(c) OpenStreetMap Contributers"))),
      ],
    );
  }
}
