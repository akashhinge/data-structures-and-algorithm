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
