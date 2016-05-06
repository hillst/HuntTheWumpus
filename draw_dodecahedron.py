#!/usr/bin/env python
from graphviz import Digraph, Graph
g = Graph('G', filename='cluster.gv', engine='neato')
#6 8 12 10 14 are inner ring, lets change these to be 6 7 8 9 10
#7 9 11 13 15 are going to be 11 12 13 14 15
#first ring
g.edge('0', '1')
g.edge('0', '5')

g.edge('1', '2')
g.edge('1', '6')

g.edge('2', '3')
g.edge('2', '7')

g.edge('3', '4')
g.edge('3', '8')

g.edge('4', '0')
g.edge('4', '9')

#second ring
g.edge('5', '10')

g.edge('10', '6')
g.edge('10', '15')

g.edge('6', '11')

g.edge('11', '7')
g.edge('11', '16')

g.edge('7', '12')

g.edge('12', '8')
g.edge('12', '17')

g.edge('8', '13')

g.edge('13', '9')
g.edge('13', '18')

g.edge('9', '14')

g.edge('14', '5')
g.edge('14', '19')

#third ring
"""
g.edge('20', '16')
g.edge('16', '17')
g.edge('17', '18')
g.edge('18', '19')
g.edge('19', '20')
"""
for i in range( 20):
    g.node(str(i), label=str(i), shape='circle')

g.view()
