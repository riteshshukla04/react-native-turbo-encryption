import { useState } from 'react';
import {
  View,
  Text,
  Button,
  StyleSheet,
  ScrollView,
  Alert,
} from 'react-native';
import {
  encrypt,
  decrypt,
  encryptAsync,
  decryptAsync,
  encrypt256,
  decrypt256,
  encrypt256Async,
  decrypt256Async,
} from 'react-native-turbo-encryption';

export default function App() {
  const plainText = 'DSP Siraj is the best Batsman in the world';
  const key = 'I only Believe on Jassi Bhai';
  const [encryptedText, setEncryptedText] = useState('');
  const [decryptedText, setDecryptedText] = useState('');
  const [useAES256, setUseAES256] = useState(false);

  const handleEncrypt = () => {
    try {
      const encrypted = useAES256
        ? encrypt256(plainText, key)
        : encrypt(plainText, key);
      setEncryptedText(encrypted);
      Alert.alert(
        'Success',
        `Text encrypted successfully with ${useAES256 ? 'AES-256' : 'AES-128'}!`
      );
    } catch (error) {
      Alert.alert('Error', (error as any).message as any);
    }
  };

  const handleDecrypt = () => {
    try {
      const decrypted = useAES256
        ? decrypt256(encryptedText, key)
        : decrypt(encryptedText, key);
      setDecryptedText(decrypted);
      Alert.alert(
        'Success',
        `Text decrypted successfully with ${useAES256 ? 'AES-256' : 'AES-128'}!`
      );
    } catch (error) {
      Alert.alert('Error', (error as any).message as any);
    }
  };

  const handleEncryptAsync = async () => {
    try {
      const encrypted = useAES256
        ? await encrypt256Async(plainText, key)
        : await encryptAsync(plainText, key);
      setEncryptedText(encrypted);
      Alert.alert(
        'Success',
        `Text encrypted successfully with ${useAES256 ? 'AES-256' : 'AES-128'}!`
      );
    } catch (error) {
      Alert.alert('Error', (error as any).message as any);
    }
  };

  const handleDecryptAsync = async () => {
    try {
      const decrypted = useAES256
        ? await decrypt256Async(encryptedText, key)
        : await decryptAsync(encryptedText, key);
      setDecryptedText(decrypted);
      Alert.alert(
        'Success',
        `Text decrypted successfully with ${useAES256 ? 'AES-256' : 'AES-128'}!`
      );
    } catch (error) {
      Alert.alert('Error', (error as any).message as any);
    }
  };

  return (
    <ScrollView contentContainerStyle={styles.container}>
      <Text style={styles.title} />

      <Text style={styles.label}>Plain Text:</Text>
      <Text style={styles.output}>{plainText}</Text>

      <Text style={styles.label}>Key:</Text>
      <Text style={styles.output}>{key}</Text>

      <Text style={styles.label}>AES Type:</Text>
      <View style={styles.buttonContainer}>
        <Button
          title={`AES-128 ${!useAES256 ? '(Active)' : ''}`}
          onPress={() => setUseAES256(false)}
          color={!useAES256 ? '#007BFF' : '#6C757D'}
        />
        <Button
          title={`AES-256 ${useAES256 ? '(Active)' : ''}`}
          onPress={() => setUseAES256(true)}
          color={useAES256 ? '#007BFF' : '#6C757D'}
        />
      </View>

      <View style={styles.buttonContainer}>
        <Button title="Encrypt" onPress={handleEncrypt} color="#007BFF" />
        <Button
          title="Encrypt Async"
          onPress={handleEncryptAsync}
          color="#28A745"
        />
      </View>

      <Text style={styles.label}>Encrypted Text:</Text>
      <Text style={styles.output}>{encryptedText}</Text>

      <View style={styles.buttonContainer}>
        <Button title="Decrypt" onPress={handleDecrypt} color="#007BFF" />
        <Button
          title="Decrypt Async"
          onPress={handleDecryptAsync}
          color="#28A745"
        />
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
