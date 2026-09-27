# First Non-Repeating Character in a String

This solution uses Java streams and lambdas to find the first character that
appears exactly once in a string. It preserves the order of characters, so
"first" means the earliest character in the original input.

## Java solution

Save the source as `first-non-repeating-character-in-string.java`.

```java
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Optional;
import java.util.Scanner;
import java.util.function.Function;
import java.util.stream.Collectors;

class FirstNonRepeatingCharacter {
    private static Optional<Character> firstNonRepeatingCharacter(String input) {
        return input.chars()
                .mapToObj(value -> (char) value)
                .collect(Collectors.groupingBy(
                        Function.identity(),
                        LinkedHashMap::new,
                        Collectors.counting()))
                .entrySet()
                .stream()
                .filter(entry -> entry.getValue() == 1)
                .map(Map.Entry::getKey)
                .findFirst();
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter a string: ");
            String input = scanner.nextLine();

            Optional<Character> result = firstNonRepeatingCharacter(input);
            if (result.isPresent()) {
                result.ifPresent(character ->
                        System.out.println("First non-repeating character: " + character));
            } else {
                System.out.println("No non-repeating character found.");
            }
        }
    }
}
```

## Step-by-step explanation

1. `input.chars()` makes a stream of the input's character values.
2. `.mapToObj(value -> (char) value)` converts each value to a `Character`
   object so it can be used as a map key.
3. `Collectors.groupingBy(...)` groups identical characters and counts them:
   - `Function.identity()` uses each character itself as the key.
   - `LinkedHashMap::new` keeps keys in their first-seen order.
   - `Collectors.counting()` counts each character's occurrences.
4. `.entrySet().stream()` streams the map's character/count pairs.
5. `.filter(entry -> entry.getValue() == 1)` keeps characters that appear once.
6. `.map(Map.Entry::getKey)` selects the character from each remaining pair.
7. `.findFirst()` returns the earliest such character as an `Optional`. The
   `Optional` is empty if every character repeats.
8. `main` reads a full line, calls the method, and prints either the character
   or a message saying none was found.

## Example

For input `swiss`, the counts in insertion order are `s = 3`, `w = 1`, and
`i = 1`. The first character with a count of one is `w`, so the output is:

```text
First non-repeating character: w
```

If the input is `aabb`, every character occurs twice, so the program prints:

```text
No non-repeating character found.
```

## Complexity

- **Time:** O(n), where n is the number of characters. The input is traversed
  to count characters and then the counts are searched.
- **Space:** O(k), where k is the number of distinct characters.

## Compile and run

The source file uses a package-private class so it can use the requested
hyphenated filename. Compile and run it from the directory containing the
file:

```text
javac first-non-repeating-character-in-string.java
java FirstNonRepeatingCharacter
```
