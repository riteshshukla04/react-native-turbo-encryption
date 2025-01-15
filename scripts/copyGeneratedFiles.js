const fs = require('fs');
const path = require('path');

/**
 * Recursively copies files from the source directory to the destination directory.
 * @param {string} src - The source directory.
 * @param {string} dest - The destination directory.
 */
function copyDirectory(src, dest) {
  if (!fs.existsSync(src)) {
    console.error(`Source directory "${src}" does not exist.`);
    return;
  }

  if (!fs.existsSync(dest)) {
    fs.mkdirSync(dest, { recursive: true });
  }

  const entries = fs.readdirSync(src, { withFileTypes: true });

  entries.forEach(entry => {
    const srcPath = path.join(src, entry.name);
    const destPath = path.join(dest, entry.name);

    if (entry.isDirectory()) {
      copyDirectory(srcPath, destPath);
    } else {
      fs.copyFileSync(srcPath, destPath);
    }
  });

  console.log(`Successfully copied files from "${src}" to "${dest}".`);
}

// Define source and destination directories relative to the package's directory in node_modules
const packageDir = __dirname; // Directory where this script is located
const srcDir = path.resolve(packageDir, 'ios/generated');
const destDir = path.resolve(packageDir, 'build/generated/ios');

// Trigger the file copy
try {
  copyDirectory(srcDir, destDir);
} catch (error) {
  console.error('Error during file copying:', error);
}
