// import javax.crypto.Cipher;
// import javax.crypto.KeyGenerator;
// import javax.crypto.SecretKey;
//  import javax.crypto.spec.SecretKeySpec;
//import java.util.Base64;
import javax.crypto.*;
import java.util.*;

public class DESExample {

    public static void main(String[] args) throws Exception {
        String plainText = "Hello world.";
        System.out.println("Original Text: " + plainText);

        // Generate DES key
        SecretKey sk = generateKey();

        // Encrypt the text
        String encryptedText = encrypt(plainText, sk);
        System.out.println("Encrypted Text: " + encryptedText);

        // Decrypt the text
        String decryptedText = decrypt(encryptedText, sk);
        System.out.println("Decrypted Text: " + decryptedText);
    }

    // Generate a DES key
    public static SecretKey generateKey() throws Exception {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("DES");
        return keyGenerator.generateKey();
    }

    // Encrypt using DES
    public static String encrypt(String plainText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("DES");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = cipher.doFinal(plainText.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    // Decrypt using DES
    public static String decrypt(String encryptedText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("DES");
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] encryptedBytes = Base64.getDecoder().decode(encryptedText);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        return new String(decryptedBytes);
    }
}

/*
 * // import javax.crypto.Cipher;
// import javax.crypto.KeyGenerator;
// import javax.crypto.SecretKey;
//  import javax.crypto.spec.SecretKeySpec;
//import java.util.Base64;
import javax.crypto.*;
import java.util.*;

public class DESExample {

    public static void main(String[] args) throws Exception {
        String plainText = "Hello world.";
        System.out.println("Original Text: " + plainText);

        // Generate DES key
        SecretKey sk = generateKey();

        // Encrypt the text
        String encryptedText = encrypt(plainText, sk);
        System.out.println("Encrypted Text: " + encryptedText);

        // Decrypt the text
        String decryptedText = decrypt(encryptedText, sk);
        System.out.println("Decrypted Text: " + decryptedText);
    }

    // Generate a DES key
    public static SecretKey generateKey() throws Exception {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("DES")
        return keyGenerator.generateKey();
    }

    // Encrypt using DES
    public static String encrypt(String plainText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("DES");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = cipher.doFinal(plainText.getBytes());
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    // Decrypt using DES
    public static String decrypt(String encryptedText, SecretKey secretKey) throws Exception {
        Cipher cipher = Cipher.getInstance("DES");
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] encryptedBytes = Base64.getDecoder().decode(encryptedText);
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
        return new String(decryptedBytes);
    }
}
 */