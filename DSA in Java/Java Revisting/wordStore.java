import java.util.*;


public class wordStore {
    public static void main(String args[]){
        String para = "vneriub fer rfer fjher f erferf er fr f erhf re ";

        String words[] = para.split(" ");

        HashMap<String,Integer> mp = new HashMap<>();
        TreeSet<String> ts = new TreeSet<>();

        for(int i=0;i<words.length;i++){
            mp.put(words[i],mp.getOrDefault(words[i],0)+1);
            ts.add(words[i]);
        }

        for(int i=0;i<words.length;i++){
            if(mp.get(words[i])==1){
                System.out.println("1st non duplicate word : " + words[i]);
                break;
            }
        }
        
        String mostFreqWord = words[0];
        int freq = mp.get(words[0]);

        System.out.println("Duplicate words");
        
        for(String key:mp.keySet()){
            if(mp.get(key)>1){
                System.out.print(key + " ");
            }

            if(freq<mp.get(key)){
                mostFreqWord = key;
                freq = mp.get(key);
            }
        }

        System.out.println();
        System.out.println("Most frequent word in the para : "+mostFreqWord);


        System.out.println("Aplphabet Ordering of unique words in the para :");
        for(String key:ts){
            System.out.print(key + " ");
        }
        System.out.println();
    }
}
