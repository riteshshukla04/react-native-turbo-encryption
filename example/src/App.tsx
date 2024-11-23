import { StyleSheet, View, Text } from 'react-native';
import { decrypt, encrypt } from 'react-native-turbo-encryption';

const result = decrypt("d5abd060cabef46eb2bc029dec9eb788", "mysecurekey12345");

export default function App() {
  console.log(result);
  return (
    <View style={styles.container}>
      <Text>Result: {result}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
