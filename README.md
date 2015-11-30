# 2015复旦大学数据结构

## Data Reformat

Explaination of the format of **shanghai_map.in**

```
numbers of nodes
id0 lat0 lon0
id1 lat1 lon1
...
numbers of edges
node_id0_a node_id1_a
... 
```

sample input

```
3
0 0 0
1 0 1
2 1 0
3 
0 1
1 2
2 0
```

hint: The sample input describe a triangle.


## About Ways Filter

According to the reference, only **highway** of

```
motoway
trunk
primary
secondary
tertiaty
unclassified
residental
motoway_link
trunk_link
primary_link
tertiary_link
road
```
are selected.

Visit [map feature](http://wiki.openstreetmap.org/wiki/Map_Features) for more details.


## Other Usage:
see **extract_nodes.py**
