Steps
=====

1. build graph, adj style, root(s) are courses with 0 dependency
1a. nodes to keep amount of dependent courses

2. prepare result vector (courses idx)
3. do bfs-kind iteration
4. pick a node from queue, iterate through all-sub nodes dec by 1 their dependency counter (they may have many parent roots)
   put to the queue only nodes with 0 dependency counter
5. repeat till queue will be empty
6. if # of items in result is < then amount courses - it were loops! return empty result
