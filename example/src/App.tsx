import { StyleSheet, View, Text } from 'react-native';
import { decrypt, encrypt } from 'react-native-turbo-encryption';

const sss = encrypt("I only Believe on Jassi Bhai because game changer player he is", "DSPSirajOfficial");

console.log(sss)
const result = decrypt(sss, "DSPSirajOfficial");

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
