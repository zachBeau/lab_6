#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;
/**
 * Create the PotionBrewer Class Template
 * Define a class template PotionBrewer that can handle different types of ingredients (e.g., int, double, std::string).
 * The class should have a private attribute:
 * ingredients (std::vector<T>): A vector that stores the ingredients of type T.
 * Implement the following public methods:
 * addIngredient(T ingredient): Adds an ingredient to the list.
 * brewPotion(): Simulates the brewing process and returns the potion’s effectiveness
 *  based on the ingredients. The effectiveness is calculated by adding all of the
 *  ingredients together. Throw an exception if there are no ingredients to brew.
 *  Afther the potion is brewed, the ingredients list should be cleared.
 */
template <typename T>
class PotionBrewer
{
    vector<T> ingredients;

public:
    void addIngredient(T ingredient) {
        ingredients.push_back(ingredient); 
        cout << "Added ingredient: " << ingredient << endl; 
    }
    T brewPotion() {
        if (ingredients.empty()) {
            throw out_of_range("There are no ingredients to brew potion with");
        }

        T brew{}; 
        for (int i = 0; i < ingredients.size(); i++) {
            brew += ingredients.at(i); 
        }
        ingredients.clear(); 
        return brew; 
    }
};
/**
 * Implement a specialization of the brewPotion() method for std::string type ingredients.
 * This specialization should concatenate the strings and handle any invalid
 * combinations (e.g., if a forbidden word is present, throw an exception).
 * The only forbidden ingredient is "poison".
 */
template <> 
string PotionBrewer<string>::brewPotion() {        
    if (ingredients.empty()) {
        throw out_of_range("Empty cauldron error! There are no ingredients to brew potion with");
    }

    string brew = ""; 
    for (int i = 0; i < ingredients.size(); i++) {
        if (ingredients.at(i) == "poison" || ingredients.at(i) == "Poison") {
            throw invalid_argument("Evil error! Murder is frowned upon. Remove poison");
        }
        brew += ingredients.at(i); 
    }
    ingredients.clear();
    return brew; 
}

int main()
{
    /**
     * Brew a Potion with Numeric Ingredients (Strength Potion)
     * Create an instance of PotionBrewer<int> and add integer ingredients representing different strengths (5, 10, 20).
     * Call the brewPotion() method and print the resulting potion’s effectiveness.
     */
    PotionBrewer<int> strength; 
    strength.addIngredient(5);
    strength.addIngredient(10); 
    strength.addIngredient(20);
    try {
        int result = strength.brewPotion(); 
        cout << "Strength potion brewed! Effectiveness: " << result << endl; 
    }
    catch (out_of_range& e) {
        cout << "\tERROR: " << e.what() << endl; 
    }
    catch (invalid_argument& e) {
        cout << "\tERROR: " << e.what() << endl; 
    }
    /**
     * Brew a Potion with Double Ingredients (Healing Potion)
     * Create an instance of PotionBrewer<double> and add double ingredients representing healing powers (3.5, 7.2).
     * Call the brewPotion() method and print the resulting potion’s effectiveness.
     */
    PotionBrewer<double> heal;
    heal.addIngredient(3.5);
    heal.addIngredient(7.2);    
    try {
        double result = heal.brewPotion(); 
        cout << "Healing potion brewed! Effectiveness: " << result << endl; 
    }
    catch (out_of_range& e) {
        cout << "\tERROR: " << e.what() << endl; 
    }
    catch (invalid_argument& e) {
        cout << "\tERROR: " << e.what() << endl; 
    }
    /**
     * Brew a Potion with String Ingredients (Mystical Potion)
     * Create an instance of PotionBrewer<std::string> and add string ingredients representing mystical components ("unicorn hair", "dragon scale").
     * Call the brewPotion() method and handle any exceptions that might occur (e.g., if "poison" is added).
     */
    PotionBrewer<string> mystic; 
    mystic.addIngredient("unicorn hair");
    mystic.addIngredient("dragon scale"); 
    try {
        string result = mystic.brewPotion(); 
        cout << "Mystic potion brewed! Effectiveness: " << result << endl; 
    }
    catch (out_of_range& e) {
        cout << "\tERROR: " << e.what() << endl; 
    }
    catch (invalid_argument& e) {
        cout << "\tERROR: " << e.what() << endl; 
    }
    /**
     * Test Exception Handling (Invalid Ingredient)
     * Add an invalid ingredient ("poison") to the mystical potion and ensure that
     * the correct exception is thrown. Handle the exception and print an error message
     * from the exception.
     */
    PotionBrewer<string> mystic2;
    mystic2.addIngredient("poison");
    mystic2.addIngredient("dragon scale");
    mystic2.addIngredient("poison");
    try {
        string result = mystic2.brewPotion();
        cout << "Mystic potion brewed! Effectiveness: " << result << endl;
    }
    catch (out_of_range& e) {
        cout << "\tERROR: " << e.what() << endl; 
    }
    catch (invalid_argument& e) {
        cout << "\tERROR: " << e.what() << endl; 
    }
}
