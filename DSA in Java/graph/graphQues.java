package graph;
import java.util.*;

public class graphQues {
    static class Edge{
        int src;
        int dest;
        int wt;

        Edge(int s,int d,int wt){
            this.src=s;
            this.dest=d;
            this.wt=wt;
        }
    }
    public static void createGraph(ArrayList<Edge> graph[],int flights[][]){
        for(int i=0;i<graph.length;i++){
            graph[i] = new ArrayList<>();
        }
        for(int[] arr:flights){
            int src = arr[0];
            int dest = arr[1];
            int wt = arr[2];
            graph[src].add(new Edge(src, dest, wt));
        }
    } 
    static class pair{
        int src;
        int cost;
        int stops;
        pair(int s,int c,int st){
            src=s;
            cost=c;
            stops=st;
        }
    }
    public static int cheapestflights(ArrayList<Edge> graph[],int src,int dest,int k){
        int dist[] = new int[graph.length];
        for(int i=0;i<graph.length;i++){
            if(i!=src){
                dist[i] = Integer.MAX_VALUE;
            }
        }
        
        Queue<pair> q = new LinkedList<>();
        q.add(new pair(src,0,0));
        while(!q.isEmpty()){
            pair curr = q.remove();
            if(curr.stops>k){
                break;
            }
            for(Edge e:graph[curr.src]){
                int nbr = e.dest;
                int wt = e.wt;
                if(curr.cost+wt<dist[nbr] && curr.stops<=k){
                    dist[nbr] = curr.cost+wt;
                    q.add(new pair(nbr,dist[nbr],curr.stops+1));
                }
            }
        }
        if(dist[dest]==Integer.MAX_VALUE){
            return -1;
        }else{
            return dist[dest];
        }
    }
    static class info{
        int dest;
        int cost;
        info(int d,int c){
            dest=d;
            cost=c;
        }
    }
    public static int connectingCities(int cities[][]){
        PriorityQueue<info> pq = new PriorityQueue<>((a,b)->a.cost-b.cost);
        pq.add(new info(0, 0));
        int finalCost=0;
        boolean vis[] = new boolean[cities.length];
        while(!pq.isEmpty()){
            info curr = pq.remove();
            if(!vis[curr.dest]){
                vis[curr.dest] = true;
                finalCost+=curr.cost;
                for(int i=0;i<cities.length;i++){
                    if(cities[curr.dest][i]!=0){
                        pq.add(new info(i,cities[curr.dest][i]));
                    }
                }
            }
        }
        return finalCost;
    }
    public static void main(String[] args) {
        // int n = 4;
        // int flights[][] = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
        // @SuppressWarnings("unchecked")
        // ArrayList<Edge> graph[] = new ArrayList[n];
        // createGraph(graph,flights);
        // System.out.println("cheapest route in atmost k stops : "+cheapestflights(graph,0,3,1));

        // int cities[][] = {{0,1,2,3,4},
        //                   {1,0,5,0,7},
        //                   {2,5,0,6,0},
        //                   {3,0,6,0,0},
        //                   {4,7,0,0,0}};
        // System.out.println(connectingCities(cities));
        
    }
}
//java graphQues.java