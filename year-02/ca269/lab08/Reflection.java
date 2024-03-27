import java.lang.reflect.Method;

class A {
    public String f_A;
}

class B extends A { }

interface X {
    void m_X();
}

class C extends B implements X {
    private String f_C;
    public void m_X() { }
}

class Reflection{

    static boolean checkField(Class obj, String key){
        if( obj == null || obj.equals(Object.class) )
        {
            return false;
        }

        try
        {
            obj.getDeclaredField(key);
            return true;
        }
        catch(NoSuchFieldException e)
        {
            return checkField(obj.getSuperclass(), key);
        }
    }

    @SuppressWarnings("unchecked")
    static boolean checkMethod(Class obj, String key){
        if( obj == null || obj.equals(Object.class) )
        {
            return false;
        }

        try
        {
            obj.getDeclaredMethod(key);
            return true;
        }
        catch(NoSuchMethodException e)
        {
            return checkMethod(obj.getSuperclass(), key);
        }
    }

    static boolean isClass(Class obj){
        return !Reflection.isInterface(obj);
    }

    static boolean isInterface(Class obj){
        if( obj.isInterface() ){
            return true;
        }
        return false;
    }

    static boolean hasAncestorHelper(Class obj, String key){
        if( obj == null || obj.equals(Object.class) )
        {
            return false;
        }

        //check the name of the current class
        if(obj.getName() == key){
            return true;
        }
        
        //recursive call
        return hasAncestorHelper(obj.getSuperclass(), key);
        
    }

    static boolean hasAncestor(Class obj, String key){
        //check for interfaces
        for(Class interf: obj.getInterfaces()){
            if(interf.getName() == key){
                return true;
            }
        }

        return hasAncestorHelper(obj.getSuperclass(), key);
    }

    public String WishYouA(){
        return "Happy St. Patrick's Day!";
    }
    public static void main(String[] args) {
        return;
    }
}