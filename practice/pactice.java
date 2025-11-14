import java.io.*;
import  java.util.*;

public class Main{
    public static void main(String[] args) throws IOException{
        Scanner scan=new Scanner(System.in);
        String inputFile=scan.nextLine();
        String backupFile=scan.nextLine();
        String reportFile=scan.nextLine();
        String logFile=scan.nextLine();
        int n=scan.nextInt();
        scan.nextLine();
        
        PrintStream writer=new PrintStream(new FileOutputStream(inputFile));
        for(int i=0;i<n;i++){
            writer.println(scan.nextLine());
        }
        writer.close();
        
        BufferedInputStream bis=new BufferedInputStream(new FileInuptStream(inputFile));
        BufferedOutputStream bos=new BufferedOutputStream(new FileOutputStream(backupFile));
        int byteData;
        while((byteData=bis.read())!=-1){
            bos.write(byteData);
            //System.out.print((char) byteData);
        }
        bos.flush();bos.close();
        bis.close();
        
        CreateReportFile(inputFile,reportFile,logFile);
        
        
    }
    
    public static void CreateReportFile(String inputFile,String reportFile,String logFile){
        
        BufferedReader br=new BufferedReader(new FileReader(inputFile));
        PrintStream psReport=new PrintStream(new FileOutputStream(reportFile));
        PrintStream psLog= new PrintStream(new FileOutputStream(logFile));
        String line;
        while((line=b.readLine())==null){
            String[] parts=line.split(",");
            try{
               if(parts.length!=3){
                   psLog.println("[WARN] invalid format: "+line);
                   continue;
               }
               psReport.println(line);
            }
        }
        br.close();
        psReport.close();
        psLog.close();
        
    }
    
    public static void PrintFile(String inputFile){
        BufferedInputStream bis=new BufferedInputStream(new FileOutputStream(inputFile));
        int byteData;
        while((byteData=bis.read())!=-1){
            System.out.print((char) byteData);
        }
        bis.close();
    }
    
}