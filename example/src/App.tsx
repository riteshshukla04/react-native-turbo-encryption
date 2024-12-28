import { useState } from 'react';
import { View, Text, Button, StyleSheet, ScrollView, Alert } from 'react-native';
import { encrypt, decrypt, encryptAsync, decryptAsync } from 'react-native-turbo-encryption';

export default function App() {
  const plainText = 'DSP Siraj is the best Batsman in the world';
  const key = 'I only Believe on Jassi Bhai';
  const [encryptedText, setEncryptedText] = useState('');
  const [decryptedText, setDecryptedText] = useState('');

  const handleEncrypt = () => {
    try {
      const encrypted = encrypt(plainText, key);
      setEncryptedText(encrypted);
      Alert.alert('Success', 'Text encrypted successfully!');
    } catch (error) {
      Alert.alert('Error', error.message);
    }
  };

  const handleDecrypt = () => {
    try {
      const decrypted = decrypt(encryptedText, key);
      setDecryptedText(decrypted);
      Alert.alert('Success', 'Text decrypted successfully!');
    } catch (error) {
      Alert.alert('Error', error.message);
    }
  };

  const handleEncryptAsync = async () => {
    try {
      const encrypted = await encryptAsync(plainText, key);
      setEncryptedText(encrypted);
      Alert.alert('Success', 'Text encrypted successfully!');
    } catch (error) {
      Alert.alert('Error', error.message);
    }
  };

  const handleDecryptAsync = async () => {
    try {
      const decrypted = await decryptAsync(encryptedText, key);
      setDecryptedText(decrypted);
      Alert.alert('Success', 'Text decrypted successfully!');
    } catch (error) {
      Alert.alert('Error', error.message);
    }
  };

  return (
    <ScrollView contentContainerStyle={styles.container}>
      <Text style={styles.title}></Text>

      <Text style={styles.label}>Plain Text:</Text>
      <Text style={styles.output}>{plainText}</Text>

      <Text style={styles.label}>Key:</Text>
      <Text style={styles.output}>{key}</Text>

      <View style={styles.buttonContainer}>
        <Button title="Encrypt" onPress={handleEncrypt} color="#007BFF" />
        <Button title="Encrypt Async" onPress={handleEncryptAsync} color="#28A745" />
      </View>

      <Text style={styles.label}>Encrypted Text:</Text>
      <Text style={styles.output}>{encryptedText}</Text>

      <View style={styles.buttonContainer}>
        <Button title="Decrypt" onPress={handleDecrypt} color="#007BFF" />
        <Button title="Decrypt Async" onPress={handleDecryptAsync} color="#28A745" />
      </View>

      <Text style={styles.label}>Decrypted Text:</Text>
      <Text style={styles.output}>{decryptedText}</Text>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  container: {
    flexGrow: 1,
    padding: 20,
    backgroundColor: '#F8F9FA',
  },
  title: {
    fontSize: 24,
    fontWeight: 'bold',
    marginBottom: 20,
    textAlign: 'center',
    color: '#343A40',
  },
  buttonContainer: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    marginVertical: 20,
  },
  label: {
    fontSize: 16,
    fontWeight: 'bold',
    marginTop: 10,
    color: '#495057',
  },
  output: {
    fontSize: 16,
    padding: 10,
    borderColor: '#CED4DA',
    borderWidth: 1,
    borderRadius: 8,
    backgroundColor: '#FFFFFF',
    color: '#212529',
  },
});
