import xml.etree.ElementTree as ET


ALLOWED_WAY_TYPES = ["motoway", "trunk", "primary", "secondary", "tertiaty", "unclassified", 
                    "residental", "motoway_link", "trunk_link", "primary_link", "tertiary_link", "road"]


root = ET.parse("shanghai_map").getroot()

nds = map(lambda nd: [nd.attrib["id"], nd.attrib["lat"], nd.attrib["lon"]], filter(lambda nd: nd.tag == "node", root._children))

ways = map(lambda way: map(lambda child: child.attrib["ref"], filter(lambda child: child.tag == "nd", way._children)), 
           filter(lambda way: way.tag == "way" and reduce(lambda x,a: x or a, map(lambda child: child.tag == "tag" and child.attrib["k"] == "highway" and child.attrib["v"] in ALLOWED_WAY_TYPES, way._children)),
               root._children)
        )

edges = reduce(lambda a, way: a + zip(way[:-1], way[1:]), [[]] + ways)

print len(nds)
for nd in nds:
    print nd[0], nd[1], nd[2]

print len(edges)
for edge in edges:
    print edge[0], edge[1]
