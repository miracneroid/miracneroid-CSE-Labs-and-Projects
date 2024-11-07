/*
 * Program to demnstarte the scope of a variable
 */

public class main7 {
    public static void main(String[] args) {
        int mainScopeVariable = 10;
        System.out.println("Value of mainScopeVariable: " + mainScopeVariable);

        if (true) {
        
            int ifScopeVariable = 20;
            System.out.println("Value of ifScopeVariable: " + ifScopeVariable);
            
            System.out.println("Using mainScopeVariable within if block: " + mainScopeVariable);
        }

        //System.out.println("Cannot access ifScopeVariable here: " + ifScopeVariable);

        System.out.println("Using mainScopeVariable outside if block: " + mainScopeVariable);

        int uninitializedVariable;
       
        //System.out.println("Uninitialized variable: " + uninitializedVariable);
    }
}
