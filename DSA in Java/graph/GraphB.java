package graph;
import java.util.*;

public class GraphB {
    static class Edge implements Comparable<Edge>{
        int src;
        int dest;
        int wt;
        public Edge(int s,int d,int w){
            this.src=s;
            this.dest=d;
            this.wt=w;
        }
        public int compareTo(Edge e2){
            return this.wt-e2.wt;
        }
    }
    public static void createGraph(ArrayList<Edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i] = new ArrayList<>();
        }
        // 0 index
        graph[0].add(new Edge(0, 1, 10));
        graph[0].add(new Edge(0, 2, 15));
        graph[0].add(new Edge(0, 3, 30));
        // 1 index
        graph[1].add(new Edge(1, 0, 10));
        graph[1].add(new Edge(1, 2, 40));
        // 2 index
        graph[2].add(new Edge(2, 0, 15));
        graph[2].add(new Edge(2, 1, 40));
        // 3 index
        graph[3].add(new Edge(3, 0, 30));
        graph[3].add(new Edge(3, 4, 50));
        //graph[3].add(new Edge(3, 5, 40));
        // 4 index
        graph[4].add(new Edge(4, 3, 40));
        //graph[4].add(new Edge(4, 5, 40));
        // 5 index
        //graph[5].add(new Edge(5, 3, 40));
        //graph[5].add(new Edge(5, 4, 40));
    }
    public static void bfs(ArrayList<Edge> graph[]){
        boolean vis[] = new boolean[graph.length];
        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                bfsUtil(graph,vis);
            }
        }
    }
    public static void bfsUtil(ArrayList<Edge> graph[],boolean vis[]){ //O(V+E)
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        while(!q.isEmpty()){
            int curr = q.remove();
            if(!vis[curr]){
                vis[curr]=true;
                System.out.print(curr+" ");
                for(int i=0;i<graph[curr].size();i++){
                    Edge e = graph[curr].get(i);
                    q.add(e.dest);
                }
            }
        }
    }
    public static void dfs(ArrayList<Edge> graph[]){
        boolean vis[] = new boolean[graph.length];
        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                dfsUtil(null, i, vis);
            }
        }
    }
    public static void dfsUtil(ArrayList<Edge> graph[],int curr,boolean vis[]){ //O(V+E)
        vis[curr]=true;
        System.out.print(curr+" ");
        
        for(int i=0;i<graph[curr].size();i++){
            int neighbour = graph[curr].get(i).dest;
            if(!vis[neighbour]){
                dfsUtil(graph,neighbour,vis);
            }
        }
    }
    public static boolean hasPath(ArrayList<Edge> graph[],int src,int dest,boolean vis[]){ //O(V+E)
        if(src==dest){
            return true;
        }
        vis[src]=true;

        for(int i=0;i<graph[src].size();i++){
            Edge e = graph[src].get(i);
            int ngbr = e.dest;
            if(!vis[ngbr] && hasPath(graph,ngbr,dest,vis)){
                return true;
            }
        }

        return false;
    } 
    public static boolean detectCycle2(ArrayList<Edge> graph[]){
        boolean vis[]=new boolean[graph.length];

        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                return detectCycle2Util(graph,i,-1,vis);
            }
        }
        return false;
    }
    public static boolean detectCycle2Util(ArrayList<Edge> graph[],int curr,int par,boolean vis[]){
        vis[curr]=true;

        for(int i=0;i<graph[curr].size();i++){
            Edge e = graph[curr].get(i);
            //not visited nbr
            if(!vis[e.dest]){
                if(detectCycle2Util(graph, e.dest, curr, vis)) return true;
            }
            //visited and not par
            else if(vis[e.dest] && e.dest!=par){
                return true;//cycle
            }
            //otherwise move to next nbr
        }
        return false;
    }
    public static boolean isBipartite(ArrayList<Edge> graph[]){
        int col[] = new int[graph.length];
        for(int i=0;i<col.length;i++){
            col[i]=-1;
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<graph.length;i++){
            if(col[i]==-1){
                q.add(i);
                col[i]=0;
                while(!q.isEmpty()){
                    int curr = q.remove();
                    for(int j=0;j<graph[curr].size();j++){
                        Edge e = graph[curr].get(j);
                        if(col[e.dest]==-1){
                            int nextcol = col[curr]==0?1:0;
                            col[e.dest]=nextcol;
                            q.add(e.dest);
                        }else if(col[e.dest]==col[curr]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    public static boolean isCycle1(ArrayList<Edge> graph[]){
        boolean vis[] = new boolean[graph.length];
        boolean stack[] = new boolean[graph.length];
        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                if(isCycleUtil1(graph,i,vis,stack)){
                    return true;
                }
            }
        }
        return false;
    }
    public static boolean isCycleUtil1(ArrayList<Edge> graph[],int curr,boolean vis[],boolean stack[]){
        vis[curr]=true;
        stack[curr]=true;
        for(int i=0;i<graph[curr].size();i++){
            Edge e = graph[curr].get(i);
            if(stack[e.dest]){
                return true;
            }
            else if(!vis[e.dest] && isCycleUtil1(graph, e.dest, vis, stack)){
                return true;
            }
        }
        stack[curr]=false;
        return false;
    }
    public static void topSort(ArrayList<Edge> graph[]){
        boolean vis[]=new boolean[graph.length];
        Stack<Integer> s = new Stack<>();
        
        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                topSortUtil(graph,i,vis,s);
            }
        }

        while(!s.isEmpty()){
            System.out.print(s.pop()+" ");
        }
    }
    public static void calIndeg(ArrayList<Edge>[] graph,int indeg[]){
        for(int i=0;i<graph.length;i++){
            int v = i;
            for(int j=0;j<graph[v].size();j++){
                Edge e = graph[v].get(j);
                indeg[e.dest]++;
            }
        }
    }
    public static void topSortBfs(ArrayList<Edge>[] graph){
        int indeg[] = new int[graph.length];
        calIndeg(graph,indeg);
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<graph.length;i++){
            if(indeg[i]==0){
                q.add(i);
            }
        }
        //bfs
        while(!q.isEmpty()){
            int curr = q.poll();
            System.out.print(curr+" ");//print topological Sort
            for(int i=0;i<graph[curr].size();i++){
                Edge e = graph[curr].get(i);
                indeg[e.dest]--;
                if(indeg[e.dest]==0){
                    q.add(e.dest);
                }
            }
        }
    }
    static class pair implements Comparable<pair>{
        int node;
        int dist;
        pair(int n,int d){
            this.node=n;
            this.dist=d;
        }
        public int compareTo(pair p2){
            return this.dist-p2.dist;
        }
    }
    public static void dijkstra(ArrayList<Edge>[] graph){
        int dist[] = new int[graph.length];
        boolean vis[] = new boolean[graph.length];
        int src=0;

        for(int i=0;i<graph.length;i++){
            if(i!=src){
                dist[i]=Integer.MAX_VALUE;
            }
        }

        PriorityQueue<pair> pq = new PriorityQueue<>();
        pq.add(new pair(src,0));

        while(!pq.isEmpty()){
            pair curr = pq.poll();
            if(!vis[curr.node]){
                vis[curr.node]=true;
                for(int i=0;i<graph[curr.node].size();i++){
                    Edge e = graph[curr.node].get(i);
                    int u = curr.node;
                    int v = e.dest;
                    int wt = e.wt;
                    if(dist[u]+wt<dist[v]){
                        dist[v]=dist[u]+wt;
                        pq.add(new pair(v, dist[v]));
                    }
                }
            }
        }
        //print min dist of all node from src
        for(int i=0;i<graph.length;i++){
            System.out.println("min Dist from "+src+" to "+i+" = "+dist[i]);
        }
    }
    public static boolean isCycle2_bfs(ArrayList<Edge>[] graph){
        boolean vis[] = new boolean[graph.length];
        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                if(isCycle2_bfsUtil(graph,i,vis)) return true;
            }
        }
        return false;
    }
    public static boolean isCycle2_bfsUtil(ArrayList<Edge>[] graph,int src,boolean[] vis){
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        while(!q.isEmpty()){
            int curr = q.poll();
            if(vis[curr]) return true;
            vis[curr]=true;
            for(int i=0;i<graph[curr].size();i++){
                Edge e = graph[curr].get(i);
                if(!vis[e.dest]){
                    q.add(e.dest);
                }
            }
        }
        return false;
    }
    public static void createGraph2(ArrayList<Edge> graph){
        graph.add(new Edge(0, 1, 2));
        graph.add(new Edge(0, 2, 4));
        graph.add(new Edge(1, 2, -4));
        graph.add(new Edge(2, 3, 2));
        graph.add(new Edge(3, 4, 4));
        graph.add(new Edge(4, 1, -1));
    }
    public static void bellmanFord(ArrayList<Edge> graph,int src,int V){
        int dist[] = new int[V];
        for(int i=0;i<V;i++){
            if(i!=src){
                dist[i]=Integer.MAX_VALUE;
            }
        }
        for(int i=1;i<=V-1;i++){
            for(int j=0;j<graph.size();j++){      //O(E)
                Edge e = graph.get(j);
                int u = e.src;
                int v = e.dest;
                int wt = e.wt;
                if(dist[u]!=Integer.MAX_VALUE && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        //print min dist
        for(int i=0;i<V;i++){
            System.out.print(dist[i]+" ");
        }
    }
    static class tuple{
        int v;
        int cost;
        tuple(int v,int cost){
            this.v=v;
            this.cost=cost;
        }
    }
    public static void prims(ArrayList<Edge>[] graph){
        boolean vis[] = new boolean[graph.length];
        PriorityQueue<tuple> pq = new PriorityQueue<>((x,y)->x.cost-y.cost);
        pq.add(new tuple(0, 0));
        int finalCost = 0;

        while(!pq.isEmpty()){
            tuple curr = pq.remove();
            if(vis[curr.v]) continue;
            vis[curr.v] = true;
            finalCost+=curr.cost;
            for(int i=0;i<graph[curr.v].size();i++){
                Edge e = graph[curr.v].get(i);
                if(!vis[e.dest]){
                    pq.add(new tuple(e.dest, e.wt));
                }
            }
        }
        System.out.println("final min cost = "+finalCost);
    }
    //Union Find
    static int n;//no. of vertices
    static int par[];
    static int rank[];
    public static void init(int m){
        n=m;
        par = new int[n];
        rank = new int[n];
        for(int i=0;i<par.length;i++){
            par[i]=i;
        }
    }
    public static int find(int x){
        if(x==par[x]){
            return x;
        }
        //path compression
        return par[x]=find(par[x]);
    }
    public static void Union(int a,int b){
        int parA = find(a);
        int parB = find(b);
        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB] = parA;
        }else{
            par[parA] = parB;
        }
    }
    public static void createEdges(ArrayList<Edge> edges){
        //edges
        edges.add(new Edge(0, 1, 10));
        edges.add(new Edge(0, 2, 15));
        edges.add(new Edge(0, 3, 30));

        edges.add(new Edge(1, 3, 40));
        edges.add(new Edge(2, 3, 50));
    }
    public static int KruskalAlgo(ArrayList<Edge> edges,int V){
        init(V);
        Collections.sort(edges);
        int minCost=0;
        int count=0;
        for(int i=0;count<V-1;i++){
            Edge e = edges.get(i);
            int src = e.src;
            int dest = e.dest;
            int wt = e.wt;

            int parA=par[src];
            int parB=par[dest];
            if(parA!=parB){
                Union(src,dest);
                minCost+=wt;
                count++;
            } 
        }
        return minCost;
    }
    public static void topSortUtil(ArrayList<Edge>[] graph,int curr,boolean vis[],Stack<Integer> s){
        vis[curr]=true;

        for(int i=0;i<graph[curr].size();i++){
            Edge e = graph[curr].get(i);
            if(!vis[e.dest]){
                topSortUtil(graph, e.dest, vis, s);
            }
        }

        s.push(curr);
    }
    public static void KosarajuAlgo(ArrayList<Edge> graph[],int V){
        //step 1: topsort -> stack -> order
        boolean vis[] = new boolean[V];
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topSortUtil(graph, i, vis, stack);
            }
        }
        //step 2: transpose
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] transpose = new ArrayList[V]; 
        for(int i=0;i<V;i++){
            transpose[i] = new ArrayList<>();
            vis[i]=false;
        }
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                Edge e = graph[i].get(j);
                transpose[e.dest].add(new Edge(e.dest,e.src,e.wt));
            }
        }
        //step 3: dfs(stack based) on transpose
        //Strong connected component
        while(!stack.isEmpty()){
            int curr = stack.pop();
            if(!vis[curr]){
                dfsUtil(transpose, curr, vis);
                System.out.println();
            }
        }
    }
    static int time=0;
    public static void dfs_tarjan(ArrayList<Edge>[] graph,int curr,int[] dis,int[] low,boolean[] vis,int par){
        vis[curr]=true;
        dis[curr] = low[curr] = ++time;

        for(int i=0;i<graph[curr].size();i++){
            Edge e = graph[curr].get(i);
            int nbr = e.dest;
            if(nbr!=par){
                if(!vis[nbr]){
                    dfs_tarjan(graph, nbr, dis, low, vis, curr);
                    low[curr] = Math.min(low[curr],low[nbr]);
                    if(dis[curr]<low[nbr]){
                        System.out.println("bridge of graph is "+curr+"------"+nbr);
                    }
                }
                else if(vis[nbr]){
                    low[curr] = Math.min(low[curr],dis[nbr]);
                }
            }
        }
    }
    public static void tarjanBridge(ArrayList<Edge>[] graph,int V){
        int dis[] = new int[V];
        int low[] = new int[V];
        boolean vis[] = new boolean[V];
                
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs_tarjan(graph,i,dis,low,vis,-1);
            }
        }
    }
    public static void main(String[] args) {    
        int V = 5;
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] graph = new ArrayList[V]; 
        createGraph(graph);
        // KosarajuAlgo(graph,V);
        tarjanBridge(graph,V);
    }
}
//java GraphB.java
