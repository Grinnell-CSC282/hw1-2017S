import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ConvertDOSFile {

    public static void main(String[] args) throws IOException {
        String fileName = args[0];
        Scanner scan = new Scanner(new File(fileName));
        File replace = new File("temp");

        FileWriter fw = new FileWriter(replace.getAbsoluteFile());
        BufferedWriter bw = new BufferedWriter(fw);

        while (scan.hasNextLine()) {
            String curLine = scan.nextLine();
            String newLine = curLine.replace("\r\n", "\n");

            bw.write(newLine);
        }

        bw.close();
        fw.close();
        scan.close();

        File origFile = new File(fileName);
        origFile.delete();

        replace.renameTo(origFile);
    }

}
