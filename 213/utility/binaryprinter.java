/* *****************
* Will Connell
* Prints numbers in binary. 
* Used to generate the array in 
* the decoder.
***************** */

public class binaryprinter
{
        public static void main(String args[])
        {
                String binary = "";
                for(int length=1; length<=7; length++)
                {
                        for(int i=0; i<Math.pow(2, length); i++)
                        {
                                if(i == Math.pow(2, length) - 1)
                                        continue;

                                binary = Integer.toBinaryString(i);
                                while(binary.length() < length)
                                {
                                        binary = "0" + binary;
                                }

                                System.out.print(binary + "\", \"");
                        }
                }
        }
}

