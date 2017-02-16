import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class HighestGrades {

    public static void main(String[] args) throws FileNotFoundException {
        String fileName = args[0];
        Scanner scan = new Scanner(new File(fileName));

        HashMap<String, Integer> hmap = new HashMap<String, Integer>();
        ArrayList<String> names = new ArrayList<String>();

        while (scan.hasNextLine()) {
            String curLine = scan.nextLine();
            String[] parts = curLine.split(",");

            if (parts[2].equals("howmework 2")) {
                String name = parts[0] + ", " + parts[1];

                hmap.put(name, Integer.parseInt(parts[3]));
                names.add(name);
            }
        }

        scan.close();

        int topFive[] = new int[5];
        for (int i = 0; i < 5; i++) {
            String top = names.get(i);

            for (int j = 0; j < hmap.size(); j++) {
                if (hmap.get(top) < hmap.get(names.get(j))) {
                    top = names.get(j);
                }
            }

            topFive[i] = hmap.get(top);
            hmap.remove(top);
            names.remove(top);
        }
        
        for (int k = 0; k < 5; k++) {
            System.out.println(topFive[k]);
        }

    }

}
