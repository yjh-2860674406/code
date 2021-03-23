public class Array {
    public static void main (String[] agrs)
    {
        int natrual[] = {0,1,2,3,4,5,6,7,8,9,10};
        for (int i=0; i<11; i++)
        {
            System.out.println(natrual[i]);
        }
        int size = 11;
        int[] num = new int[size];
        for (int i=0; i<11; i++)
        {
            num[i] = i;
        }
        for (int i=0; i<11; i++)
        {
            System.out.println(num[i]);
        }
    }
}
