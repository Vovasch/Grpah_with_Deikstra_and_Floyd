Here is a the realization of Floyd's and Dijkstra algorithm

This program wasn't created for cancuating pathes in any graphs.
It was created only to make laboratory work #3 and #4 using two
algorighm, this is why there is no ability to make canculation
on graph you may need.

Let's start from Dijkstra.

     At first take a look at screenshot in folder Tasks, named Dijkstratask.jpg
For every student graph is same except values of edges and beginning of graph
And every student can choose a final node from three variants: B or K or F.

Yes, it's as strange as it seems, you can also see that graph isn't directed. 
So I decided to make graph directed always from left to right and from up to bottom, 
but this borns lots of exception situations where program can't find any possible 
way to get to final node. So a half-mesure to solve this problem was to create 
another variant of graph were nodes are directed from right to left and from bottom
to down. But it still don't perfect. The best would be to direct every grpah manually,
but it's not an appropriate solution because it's too long.

-lounch the programm
-choose algorithm
-choose revesed or straight graph(dependes on location of the starting node)
-enter weights of edges
-enter starting node
-enter final node

Floyd's algorithm

   At first take a look at screenshot in floder Tasks, named Floyd's task.jpg
Fortunatelly, this graph looks better, and there is no pain in ass with
directing edges, so no errors in result. 
   There is possible '*' instead of number, it means that this edge isn't exist,
so you can easily enter * and program will define. 

-lounch the programm
-choose algorithm
-enter all values


 
