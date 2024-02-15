import java.text.DecimalFormat;

abstract class Item {
    final String name;                          
    int expiresInDays;                          
    double price;                   

    Item(String name) {
        this.name = name;
    }

    /*
    public String toString() {
        return this.name;
    }*/
}



interface StorageCondition {
    public String storageProcedure();                  //returns a String message for how an item should be stored.
}

interface Refrigerate extends StorageCondition {
    boolean refrigerate(double currentTemp);    //Takes the current temperature and returns whether the item should be refrigerated or not.
}

interface SecureItem extends StorageCondition {
    void attachSecurityTag();                   //Attaches the security tag
    boolean removeSecurityTag();                //Removes the security tag. And Returns a boolean success value.
}



interface ReducedPrice {
    double reduction(double totalAmount);       //reduction takes the total amount which could be for one or more items and returns the reduced amount.
}

interface OnSale extends ReducedPrice {
    boolean saleCondition(Item[] items);        //returns a boolean success value based on wheether the items qualify for a sale.
}



class Milk extends Item implements Refrigerate {
    int maxRefrigerateTemp;

    Milk(String name) {
        super(name);
    }

    Milk(String name, int expiresInDays, double price, int maxRefrigerateTemp){
        super(name);
        this.expiresInDays = expiresInDays;
        this.price = price;
        this.maxRefrigerateTemp = maxRefrigerateTemp;
    }

    public boolean refrigerate(double currentTemp){
        if(currentTemp > (double) maxRefrigerateTemp){
            return true;
        }
        return false;
    }

    public String storageProcedure(){
        return "refrigeration needed";
    }
}

class Bread extends Item implements StorageCondition {
    Bread(String name){
        super(name);
    }

    Bread(String name, int expiresInDays, double price){
        super(name);
        this.expiresInDays = expiresInDays;
        this.price = price;
    }

    public String storageProcedure(){
        return "Airtight Storage";
    }
}

class Perfume extends Item implements SecureItem {
    private boolean locked;

    Perfume(String name){
        super(name);
    }

    Perfume(String name, int expiresInDays, double price){
        super(name);
        this.expiresInDays = expiresInDays;
        this.price = price;
    }

    public void attachSecurityTag(){
        this.locked = true;
    }

    public boolean removeSecurityTag(){
        if(this.locked == false){
            //raise an error can not remove the tag if there is no tag
            return false;
        }
        this.locked = false;
        return true;
    }

    public boolean getLocked(){
        return this.locked;
    }

    public String storageProcedure(){
        return "Away from Sunlight";
    }
}

class PlasticCup extends Item {
    PlasticCup(String name){
        super(name);
    }

    PlasticCup(String name, int expiresInDays, double price){
        super(name);
        this.expiresInDays = expiresInDays;
        this.price = price;
    }
}

class EasterSale implements OnSale {
    final String message;
    final double minimumAmount;
    final double salePercent;

    EasterSale(double salePercent, double minimumAmount) {
        this.salePercent = salePercent / 100;
        this.minimumAmount = minimumAmount;
        DecimalFormat format = new DecimalFormat("0.#");
        this.message = "Spend over " + format.format(minimumAmount) + ", Get "
        + (this.salePercent * 100) + "% off for Easter!";
    }

    public double reduction(double totalAmount) {
        return totalAmount - (totalAmount * this.salePercent);
    }

    public boolean saleCondition(Item[] items) {
        double tot = 0;
        for(Item item: items){
            tot += item.price;
        }
        return tot >= minimumAmount;
    }

    public String toString(){
        return this.message;
    }
}


public class ShopInventory {

    public static double billItems(Item[] items, OnSale Sale){
        double tot = 0;
        for(Item item: items){
            String output = item.name + " (" + item.price + ")";

            if(item instanceof StorageCondition){
                output += " (Storage: " + ((StorageCondition)item).storageProcedure() +")";

                if(item instanceof SecureItem){
                    if(!((SecureItem)item).removeSecurityTag()){
                        System.out.println("Impossibile rimuove");
                    }
                }
            }  
            System.out.println(output);
            tot += item.price;
        }

        if(Sale == null || (!Sale.saleCondition(items))){
            return tot;
        }

        System.out.println("Actual Total: " + tot);
        System.out.println(Sale);

        return Sale.reduction(tot);
    }

    private static int getCurrentTemperature(){
        return 24;
    }

    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#.##"); // double with 2 decimal precision

        System.out.println("--- Customer 1 ---");
        Item[] items_no_sale = {
        new Milk("Avenmore Fresh", 5, 1.90, 12),
        new Bread("Bretzel Tortano", 7, 4.50),
        new Perfume("Lynx Vanilla", 500, 7),
        new PlasticCup("Tea Mug", 1200, 12),
        };
        double total_no_sale = billItems(items_no_sale, null);
        System.out.println("Total Amount: " + df.format(total_no_sale));


        System.out.println("--- Customer 2 ---");
        Item[] items_easter_sale = {
            new Milk("Mulled Wine", 60, 22.20, 8),
            new Bread("Fruit Cakes", 20, 13.50),
            new Perfume("Pot-pourri", 500, 15),
            new PlasticCup("Party Cups (set of 12)", 1200, 2),
        };
        double total_easter_sale = billItems(items_easter_sale, new EasterSale(7.5, 50));
        System.out.println("Total Amount: " + df.format(total_easter_sale));


    }
}
