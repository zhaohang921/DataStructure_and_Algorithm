/*
广度优先搜索（Breadth First Search）DFS

广度优先遍历图的方法是，从图中某顶点v出发：
（1）访问顶点v；
（2）依次从v的未被访问的邻接点出发，对图进行深度优先遍历；直至图中和v有路径相通的顶点都被访问；
（3）若此时图中尚有顶点未被访问，则从一个未被访问的顶点出发，重新进行深度优先遍历，直到图中所有顶点均被访问过为止。　

广度优先搜索使用队列（queue）来实现，整个过程也可以看做一个倒立的树形：
1、把根节点放到队列的末尾。
2、每次从队列的头部取出一个元素，查看这个元素所有的下一级元素，把它们放到队列的末尾。并把这个元素记为它下一级元素的前驱。
3、找到所要找的元素时结束程序。
4、如果遍历整个树还没有找到，结束程序。
*/

