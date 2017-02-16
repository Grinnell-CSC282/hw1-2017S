import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class SpellCheck {

    /*
     * Note: Assumed we have a file with all English words at hand, called
     * dictionary.txt
     */

    public static void main(String[] args) throws FileNotFoundException {
        String fileName = args[0];
        Scanner scan = new Scanner(new File(fileName));
        Scanner dict = new Scanner(new File("dictionary.txt"));

        HashSet<String> hset = new HashSet<String>();
        ArrayList<String> misWords = new ArrayList<String>();

        while (dict.hasNext()) {
            hset.add(dict.next());
        }

        while (scan.hasNext()) {
            String curWord = scan.next();
            if (!hset.contains(curWord)) {
                misWords.add(curWord);
            }
        }

        scan.close();
        dict.close();

        for (int i = 0; i < misWords.size(); i++) {
            System.out.println(misWords.get(i));
        }

    }

}
