import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class  Solution{
   static class Sol
   {
    static int N, M, K, L;
    static int[] arr;
	public static void main(String[] args) {
		Scanner br = new Scanner(System.in);
	        int t= br.nextInt();
	        StringBuilder sss= new StringBuilder();
	        for(int tt=0; tt<t; tt++){
	            N= br.nextInt();
	            M= br.nextInt();
	            K= br.nextInt();
	            L= br.nextInt();
	            ArrayList<Integer> list= new ArrayList<Integer>();
	            int zz;
	            for(int i=0; i<N; i++){
	                zz= br.nextInt();
	                list.add(zz);
	            }
	            int lastRemoved= 0;
	            int min= Integer.MAX_VALUE;
	            Collections.sort(list);
	            M++;
	            boolean timeOver = false;
	            for(int i=0; i<N; i++){
	                int timeFrame= list.get(i);
	                if(timeFrame <= K){
	                    int diff= timeFrame - lastRemoved;
	                    int cRem= diff/L;
	                    M -= cRem;
	                    if(min > (M*L - (diff%L))) min= M*L- (diff%L);
	                    lastRemoved += cRem*L;
	                    M++;
	                    if(timeFrame == K){
	                        timeOver= true;
	                        break;
	                    }
	                }
	                else{
	                    int diff= K - lastRemoved;
	                    int cRem= diff/L;
	                    M -= cRem;
	                    if(min > (M*L)) min= M*L;
	                    lastRemoved += cRem*L;
	                    M++; 
	                    timeOver= true;
	                    break;
	                }
	            }
	            if(timeOver == true){
	                if(min > (M*L)) min= M*L;    
	            }
	            else{
	                int remT= K - lastRemoved;
	                int za= remT / L;
	                int zm= remT % L;
	                int fs= ((M-za)*L) - zm;
	                if(fs < min) min= fs;
	            }
	            sss.append(min);
	            if(tt != t-1) sss.append("\n");}
	        System.out.print(sss);
	        br.close();
	        
	    }
	    
	    
	}
}