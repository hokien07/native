/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
//
//public class TestJavaIoFile {
//
//public static String pathNameNonExistent;
//public static String stringPathNameNonExistent;
//
//public static String pathNameExistent;
//public static String stringPathNameExistent;
//
//public static String pathUri;
//public static String stringUriPath;
//
//public static String pathTestFolder;
//public static String stringPathTestFolder;
//
//public static String pathSubFolder;
//public static String stringSubFolder;
//
//public static String pathNameAbsolute;
//public static String pathNameNotAbsolute;
//
//public static String pathNameHidden;
//
//public static String pathNameNonExistentFolder;
//
//public static boolean isLinux = Os.isLinux();
//public static boolean isWindows  = Os.isWindows();
//
//public static void setEnvironmentVariable() {
//        if (TestJavaIoFile.isLinux) {
//            TestJavaIoFile.pathNameNonExistent = "/home/thoangminh/TestFolder/NonExistentFile.txt";
//            TestJavaIoFile.pathNameExistent = "/home/thoangminh/TestFolder/test.txt";
//        }
//
//        if (TestJavaIoFile.isWindows) {
//            TestJavaIoFile.pathNameNonExistent  = "TestFolder/NonExistentFile.txt";
//            TestJavaIoFile.stringPathNameNonExistent  = "TestFolder\\NonExistentFile.txt";
//
//            TestJavaIoFile.pathNameExistent  = "TestFolder/ExistentFile.txt" ;
//            TestJavaIoFile.stringPathNameExistent  = "TestFolder\\ExistentFile.txt";
//
//            TestJavaIoFile.pathUri  = "file:///Users/admin/test.txt";
//            TestJavaIoFile.stringUriPath  = "\\Users\\admin\\test.txt";
//
//            TestJavaIoFile.pathTestFolder  = "TestFolder/";
//            TestJavaIoFile.stringPathTestFolder  = "TestFolder";
//
//            TestJavaIoFile.pathSubFolder  = "TestFolder/SubFolder";
//            TestJavaIoFile.stringSubFolder  = "TestFolder\\SubFolder";
//
//            TestJavaIoFile.pathNameAbsolute  = "C:\\TestFolder\\NonExistentFile.txt";
//            TestJavaIoFile.pathNameNotAbsolute  = "TestFolder/NonExistentFile.txt";
//
//            TestJavaIoFile.pathNameHidden  = "TestFolder/HiddenFile.txt";
//
//            TestJavaIoFile.pathNameNonExistentFolder  = "NonExistentFolder/";
//        }
//    }
//
//    @Test
//public void test00FileBeforeTesting() throws IOException {
//            // Set up environment variable
//            TestJavaIoFile.setEnvironmentVariable();
//
//            // Create varibles for testing
//            File fileTestFolder = new File(TestJavaIoFile.pathTestFolder);
//            File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//            File fileHidden = new File(TestJavaIoFile.pathNameHidden);
//            File fileSubFolder = new File(TestJavaIoFile.pathSubFolder);
//
//            fileSubFolder.mkdirs();
//            fileExistent.createNewFile();
//            fileHidden.createNewFile();
//
//            // Delete files after testing
//            fileTestFolder.deleteOnExit();
//            fileExistent.deleteOnExit();
//            fileHidden.deleteOnExit();
//            fileSubFolder.deleteOnExit();
//    }
//
//    @Test
//public void test01FileConstructor() throws URISyntaxException {
//            String filePathOfUriPath = "/Users/admin/test.txt";
//            URI uri = new URI(TestJavaIoFile.pathUri);
//
//            /* Test File(String pathname) */
//            File fileParamString = new File(TestJavaIoFile.pathTestFolder);
//            assertEquals(TestJavaIoFile.stringPathTestFolder.toString(), fileParamString.toString());
//
//            /* Test File(URI uri) */
//            File fileParamURI = new File(uri);
//            assertEquals(TestJavaIoFile.stringUriPath.toString(), fileParamURI.toString());
//
//            /* Test File(String parent, String child) */
//            File fileParamStringString = new File(TestJavaIoFile.pathTestFolder, "SubFolder");
//            assertEquals(TestJavaIoFile.stringSubFolder.toString(), fileParamStringString.toString());
//
//            /* Test File(File parent, String child) */
//            File fileParamFileString = new File(fileParamString, "SubFolder");
//            assertEquals(TestJavaIoFile.stringSubFolder.toString(), fileParamFileString.toString());
//    }
//
//    /**
//     * canExecute() doesn't test for executability,
//     * it tests whether the current program
//     * is permitted to execute it
//     * @throws IOException
//     */
//    @Test
//public void test02FileCanExecute() throws IOException {
//            // Return FALSE with non-existent file
//            File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//            assertFalse(fileNonExistent.canExecute());
//
//            // Return FASLE when can not execute
//            File fileTestFolder = new File(TestJavaIoFile.pathTestFolder);
//            File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//            fileExistent.createNewFile();
////		assertTrue(fileExistent.setExecutable(false));  // TODO(thoangminh): research it
////		assertFalse(fileExistent.canExecute());
//
//            // Return TRUE when can execute
//            assertTrue(fileExistent.setExecutable(true));
//            assertTrue(fileExistent.canExecute());
//    }
//
//    @Test
//public void test03FileCanRead() {
//        // Case FALSE
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//        assertFalse(fileNonExistent.canRead());
//
//        // Case TRUE
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//        assertTrue(fileExistent.canRead());
//    }
//
//    @Test
//public void test04FileCanWrite() {
//        if (isLinux) {
//            // Case FALSE
//            File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//            assertFalse(fileNonExistent.canWrite());
//
//            // Case TRUE
//            File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//            assertTrue(fileExistent.canWrite());
//        }
//    }
//
//    @Test
//public void test05FileCompareTo() {
//        /* Create variable to test */
//        String pathName = "aaBaa";
//
//        String pathNameLess = "aaAaa";
//        String pathNameEqual = "aaBaa";
//        String pathNameGreater = "aaCaa";
//
//        File file = new File(pathName);
//        File fileNameLess = new File(pathNameLess);
//        File fileNameEqual = new File(pathNameEqual);
//        File fileNameGreater = new File(pathNameGreater);
//
//        // Return 1 if greater than
//        assertEquals(1, file.compareTo(fileNameLess));
//
//        // Return 0 if equal
//        assertEquals(0, file.compareTo(fileNameEqual));
//
//        // Return -1 if less than
//        assertEquals(-1, file.compareTo(fileNameGreater));
//    }
//
//    @Test
//public void test06FileCreateNewFile() throws IOException {
//            /* Return TRUE + Create a new file
//               if the current file is NOT EXISTENT */
//            File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//            assertTrue(fileNonExistent.createNewFile());
//            fileNonExistent.delete();
//
//            /* Return FALSE + Do nothing
//               if the current file is EXISTENT */
//            File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//            assertFalse(fileExistent.createNewFile());
//
//            File fileTestFolder = new File(TestJavaIoFile.pathTestFolder);
//            assertFalse(fileTestFolder.createNewFile());
//    }
//
//    @Test
//public void test07FileCreateTempFileParamStringString() throws IOException {
//            File file = new File("");
//
//            if (isLinux) {
//                // Create a non-existent file
//                file = new File(TestJavaIoFile.pathNameNonExistent);
//                assertFalse(file.exists());
//            }
//
//            // Make sure the file is existent after creating a temp file.
//            file = File.createTempFile("temp", ".txt");
//            assertTrue(file.exists());
//
//            // Delete file after testing
//            assertTrue(file.delete());
//    }
//
//    @Test
//public void test08FileCreateTempFileParamStringStringFile() throws IOException {
//            File file = new File("");
//
//            if (isLinux) {
//                // Create a non-existent file
//                file = new File(TestJavaIoFile.pathNameNonExistent);
//                assertFalse(file.exists());
//            }
//
//            // Create a temp file.
//            File fileTestFolder = new File(TestJavaIoFile.pathTestFolder);
//            file = File.createTempFile("temp", ".txt", fileTestFolder);
//            String pathParentFile = file.getParentFile().toString() + "/";
//
//            // Make sure the file is existent and the directory is right
//            assertTrue(file.exists());
//            assertEquals(pathTestFolder.toString(), pathParentFile.toString());
//
//            // Delete file after testing
//            assertTrue(file.delete());
//    }
//
//    @Test
//public void test09FileDelete() throws IOException {
//            // Create a non-existent file
//            File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//            assertFalse(fileNonExistent.exists());
//
//            // Return FALSE when trying to delete is NOT SUCCESS
//            assertFalse(fileNonExistent.delete());
//
//
//            // Create a temp file.
//            File fileTemp = File.createTempFile("temp", ".txt");
//
//            // Return TRUE when trying to delete is SUCCESS
//            assertTrue(fileTemp.delete());
//
//            // Make sure the temp file is deleted
//            assertFalse(fileTemp.exists());
//    }
//
//    @Test
//public void test10FileDeleteOnExit() throws IOException {
//            if (isLinux) {
//                // Create a temp file.
//                String pathTestFolder = "/home/thoangminh/TestFolder/";
//                File fileTestFolder = new File(pathTestFolder);
//                File fileTemp = File.createTempFile("temp", ".txt", fileTestFolder);
//
//                // Deletes file when the virtual machine terminate
//                fileTemp.deleteOnExit();
//            }
//    }
//
//    @Test
//public void test11FileEquals() {
//        /* Create variable to test */
//        String pathName = "aaBaa";
//
//        String pathNameNotEqual = "aaAaa";
//        String pathNameEqual = "aaBaa";
//
//        File file = new File(pathName);
//        File fileNameNotEqual = new File(pathNameNotEqual);
//        File fileNameEqual = new File(pathNameEqual);
//
//        // Return FALSE if NOT EQUAL
//        assertFalse(file.equals(fileNameNotEqual));
//
//        // Return TRUE if EQUAL
//        assertTrue(file.equals(fileNameEqual));
//    }
//
//    @Test
//public void test12FileExists() throws IOException {
//            // Create a non-existent file
//            File file = new File(TestJavaIoFile.pathNameNonExistent);
//
//            // Return FALSE when the file is NOT EXISTENT
//            assertFalse(file.exists());
//
//            // Return TRUE when the file is EXISTENT
//            file = File.createTempFile("temp", ".txt");
//            assertTrue(file.exists());
//
//            // Delete file after testing
//            assertTrue(file.delete());
//    }
//
//    @Test
//public void test13FileGetAbsoluteFile() throws IOException {
//            if (TestJavaIoFile.isWindows) {
//
//                // Create a non-existent file
//                File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//                // Create an existent file
//                File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//                // getAbsoluteFile() when the file is NOT EXISTENT
//                String expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\NonExistentFile.txt";
//                String actual = fileNonExistent.getAbsoluteFile().toString();
//                assertEquals(expected.toString(), actual.toString());
//
//                // getAbsoluteFile() when the file is EXISTENT
//                expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\ExistentFile.txt";
//                actual = fileExistent.getAbsoluteFile().toString();
//                assertEquals(expected.toString(), actual.toString());
//            }
//    }
//
//    @Test
//public void test14FileGetAbsolutePath() throws IOException {
//            if (TestJavaIoFile.isWindows) {
//
//                // Create a non-existent file
//                File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//                // Create an existent file
//                File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//                // getAbsoluteFile() when the file is NOT EXISTENT
//                String expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\NonExistentFile.txt";
//                String actual = fileNonExistent.getAbsolutePath().toString();
//                assertEquals(expected.toString(), actual.toString());
//
//                // getAbsoluteFile() when the file is EXISTENT
//                expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\ExistentFile.txt";
//                actual = fileExistent.getAbsolutePath().toString();
//                assertEquals(expected.toString(), actual.toString());
//            }
//    }
//
//    @Test
//public void test15FileGetCanonicalFile() throws IOException {
//            if (TestJavaIoFile.isWindows) {
//                // Create an existent file
//                File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//                // Get Canonical File
//                String expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\ExistentFile.txt";
//                String actual = fileExistent.getCanonicalFile().toString();
//                assertEquals(expected.toString(), actual.toString());
//            }
//    }
//
//    @Test
//public void test16FileGetCanonicalPath() throws IOException {
//            if (isWindows) {
//                // Create an existent file
//                File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//                // Get Canonical File
//                String expected = "E:\\JavaWorkspace\\TestJavaLibrary\\TestFolder\\ExistentFile.txt";
//                String actual = fileExistent.getCanonicalPath();
//                assertEquals(expected.toString(), actual.toString());
//            }
//    }
//
//    @Test
//public void test17FileGetFreeSpace() {
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create an existent file
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//        // getFreeSpace return 0 if the file is non existent
//        assertTrue(0 == fileNonExistent.getFreeSpace());
//
//        // getFreeSpace return != 0 if the file is existent
//        assertTrue(0 != fileExistent.getFreeSpace());
//    }
//
//    @Test
//public void test18FileGetName() {
//        // Create a file has file name
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a directory file
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // getName() return the name of the file
//        String expected = "NonExistentFile.txt";
//        String actual = fileNonExistent.getName();
//        assertEquals(expected.toString(), actual.toString());
//
//        // getName() return the name of the directory
//        expected = TestJavaIoFile.stringPathTestFolder;
//        actual = fileTestFolder.getName();
//        assertEquals(expected.toString(), actual.toString());
//    }
//
//    @Test
//public void test19FileGetParent() {
//        // Create a  file has the file name
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a file doesn't has a file name
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // Returns the pathname string of this abstract pathname's parent
//        String expected = TestJavaIoFile.stringPathTestFolder;
//        String actual = fileNonExistent.getParent();
//        assertEquals(expected.toString(), actual.toString());
//
//        // Return null if this pathname does not name a parent directory
//        actual = fileTestFolder.getParent();
//        assertNull(actual);
//    }
//
//    @Test
//public void test20FileGetParentFile() {
//        // Create a  file has the file name
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a file doesn't has a file name
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // Returns the file of this abstract pathname's parent
//        String expected = TestJavaIoFile.stringPathTestFolder;
//        File actual = fileNonExistent.getParentFile();
//        assertEquals(expected.toString(), actual.toString());
//
//        // Return null file if this pathname does not name a parent directory
//        actual = fileTestFolder.getParentFile();
//        assertNull(actual);
//    }
//
//    @Test
//public void test21FileGetPath() {
//        // Create a file has file name
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a directory file
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // getPath() return the name of the file
//        String expected = TestJavaIoFile.stringPathNameNonExistent;
//        String actual = fileNonExistent.getPath();
//        assertEquals(expected.toString(), actual.toString());
//
//        // getPath() return the name of the directory
//        expected = TestJavaIoFile.stringPathTestFolder;
//        actual = fileTestFolder.getPath();
//        assertEquals(expected.toString(), actual.toString());
//    }
//
//    @Test
//public void test22FileGetTotalSpace() {
//        // Create a non-existent file
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create an existent file
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//        // Return 0 if the file is non existent
//        assertTrue(0 == fileNonExistent.getTotalSpace());
//
//        // Return != 0 if the file is existent
//        assertTrue(0 != fileExistent.getTotalSpace());
//    }
//
//    @Test
//public void test23FileGetUsableSpace() {
//        // Create a non-existent file
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create an existent file
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//        // Return 0 if the file is non existent
//        assertTrue(0 == fileNonExistent.getUsableSpace());
//
//        // Return != 0 if the file is existent
//        assertTrue(0 != fileExistent.getUsableSpace());
//    }
//
//    @Test
//public void test24FileIsAbsolute() {
//        File fileNotAbsolute = new File(TestJavaIoFile.pathNameNotAbsolute);
//        File fileAbsolute = new File(TestJavaIoFile.pathNameAbsolute);
//
//        assertFalse(fileNotAbsolute.isAbsolute());
//        assertTrue(fileAbsolute.isAbsolute());
//    }
//
//    @Test
//public void test25FileIsDirectory() {
//        // Create a file has file name
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a directory file
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // return FALSE if file is not a directory
//        assertFalse(fileNonExistent.isDirectory());
//
//        // return TRUE if file is a directory
//        assertTrue(fileTestFolder.isDirectory());
//    }
//
//    @Test
//public void test26FileIsFile() {
//        // Create a directory file
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // Create a file from a non-existent path
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a file from a existent path
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//        // return FALSE if file is a directory
//        assertFalse(fileTestFolder.isFile());
//
//        // return FALSE if file is non-existent
//        assertFalse(fileNonExistent.isFile());
//
//        // return TRUE if file is existent
//        assertTrue(fileExistent.isFile());
//    }
//
//    @Test
//public void test27FileIsHidden() {
//        // Create a directory file
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // Create a file from a non-existent path
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a file from an existent path
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//        // Create a file from an existent hidden path
//        File fileHidden = new File(TestJavaIoFile.pathNameHidden);
//
//        // return FALSE if file is a directory
//        assertFalse(fileTestFolder.isHidden());
//
//        // return FALSE if file is non-existent
//        assertFalse(fileNonExistent.isHidden());
//
//        // return FALSE if file is existent
//        assertFalse(fileExistent.isHidden());
//
//        // return TRUE if file is hidden
////		assertTrue(fileHidden.isHidden());
//    }
//
//    @Test
//public void test28FileLastModified() {
//        // Create a directory file
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // Create a file from a non-existent path
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a file from an existent path
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//        assertTrue(0 != fileTestFolder.lastModified());
//        assertTrue(0 == fileNonExistent.lastModified());
//        assertTrue(0 != fileExistent.lastModified());
//    }
//
//    @Test
//public void test29FileLength() {
//        // Create a directory file
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // Create a file from a non-existent path
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a file from an existent path
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//        assertEquals(0, fileTestFolder.length());
//        assertEquals(0, fileNonExistent.length());
//        assertEquals(0, fileExistent.length());
//    }
//
//    @Test
//public void test30FileList() {
//        // Test a not empty directory
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//        String[] expected = {"ExistentFile.txt", "HiddenFile.txt", "SubFolder"};
//        String[] actual = fileTestFolder.list();
//        assertEquals(expected[0].toString(), actual[0].toString());
//        assertEquals(expected[1].toString(), actual[1].toString());
//        assertEquals(expected[2].toString(), actual[2].toString());
//        assertEquals(3, actual.length);
//
//        // Test an empty directory
//        File fileSubFolder = new File(TestJavaIoFile.pathTestFolder + "SubFolder");
//        assertTrue(fileSubFolder.exists());
//        actual = fileSubFolder.list();
//        assertEquals(0, actual.length);
//    }
//
//    @Test
//public void test31FileListFiles() {
//        // Test a not empty directory
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//        File fileHidden = new File(TestJavaIoFile.pathNameHidden);
//        File fileSubFolder = new File(TestJavaIoFile.pathTestFolder + "SubFolder");
//        File[] expected = {fileExistent, fileHidden, fileSubFolder};
//        File[] actual = fileTestFolder.listFiles();
//        assertEquals(expected[0].toString(), actual[0].toString());
//        assertEquals(expected[1].toString(), actual[1].toString());
//        assertEquals(expected[2].toString(), actual[2].toString());
//        assertEquals(3, actual.length);
//
//        // Test an empty directory
//        assertTrue(fileSubFolder.exists());
//        actual = fileSubFolder.listFiles();
//        assertEquals(0, actual.length);
//    }
//
//    @Test
//public void test32FileListRoots() {
//
//        if (TestJavaIoFile.isWindows) {
//            // Test a not empty directory
//            File fileCDrive = new File("C:\\");
//            File fileDDrive = new File("D:\\");
//            File fileEDrive = new File("E:\\");
//            File[] expected = {fileCDrive, fileDDrive, fileEDrive};
//            File[] actual = File.listRoots();
//            assertEquals(expected[0].toString(), actual[0].toString());
//            assertEquals(expected[1].toString(), actual[1].toString());
//            assertEquals(expected[2].toString(), actual[2].toString());
//            assertEquals(3, actual.length);
//        }
//    }
//
//    @Test
//public void test33FileMkdir() {
//        // Create an existent directory file
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // Create a non-existent directory file
//        File fileNonExistentFolder
//                = new File(TestJavaIoFile.pathNameNonExistentFolder + "NonExistentFile.txt");
//
//        // Create a file from a non-existent path
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a file from a existent path
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//        // return FALSE if a directory file is existent and do nothing
//        assertFalse(fileTestFolder.mkdir());
//
//        // return FALSE if file is existent and do nothing
//        assertFalse(fileExistent.mkdir());
//
//        // return FALSE if the parent directory is non-existent
//        assertFalse(fileNonExistentFolder.mkdir());
//
//        // return TRUE if file is non-existent,
//        // and creates the directory named by this abstract pathname.
//        assertTrue(fileNonExistent.mkdir());
//        assertTrue(fileNonExistent.exists());
//
//        // delete file after testing
//        fileNonExistent.delete();
//    }
//
//    @Test
//public void test34FileMkdirs() {
//        // Create an existent directory file
//        File fileTestFolder= new File(TestJavaIoFile.pathTestFolder);
//
//        // Create a non-existent directory file
//        File fileNonExistentFolder
//                = new File(TestJavaIoFile.pathNameNonExistentFolder );
//        File fileNonExistentFolderFile
//                = new File(TestJavaIoFile.pathNameNonExistentFolder + "NonExistentFile.txt");
//
//        // Create a file from a non-existent path
//        File fileNonExistent = new File(TestJavaIoFile.pathNameNonExistent);
//
//        // Create a file from a existent path
//        File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//        // return FALSE if a directory file is existent and do nothing
//        assertFalse(fileTestFolder.mkdirs());
//
//        // return FALSE if file is existent and do nothing
//        assertFalse(fileExistent.mkdirs());
//
//        // return TRUE if the parent directory is non-existent
//        // and create the file
//        assertTrue(fileNonExistentFolderFile.mkdirs());
//        assertTrue(fileNonExistentFolder.exists());
//        assertTrue(fileNonExistentFolder.exists());
//
//        // return TRUE if file is non-existent,
//        // and creates the directory named by this abstract pathname.
//        assertTrue(fileNonExistent.mkdirs());
//        assertTrue(fileNonExistent.exists());
//
//        // delete file after testing
//        fileNonExistentFolder.deleteOnExit();
//        fileNonExistentFolderFile.deleteOnExit();
//        assertTrue(fileNonExistent.delete());
//    }
//
//    @Test
//public void test35FileRenameTo() throws IOException {
//            // Create a file from a non-existent file path
//            File fileNonExistentFile = new File(TestJavaIoFile.pathNameNonExistent);
//
//            // Create a file form a non-existent folder path
//            File fileNonExistentFoler = new File(TestJavaIoFile.pathNameNonExistentFolder);
//
//            // Create a file from an existent path
//            File fileExistent = new File(TestJavaIoFile.pathNameExistent);
//
//            // Create a file from an existent folder path
//            File fileExistentFolder = new File(TestJavaIoFile.pathTestFolder);
//
//            // Create a new file to test
//            File fileTest = new File("Test/");
//
//            // return FALSE if fileTest is non-existent
//            assertFalse(fileTest.renameTo(fileExistent));
//            assertFalse(fileTest.renameTo(fileNonExistentFoler));
//            assertFalse(fileTest.renameTo(fileExistentFolder));
//
//            /* Create a File object for fileTest variable */
//            // After that: renameTo() will return TRUE with the non-existent destination
//            assertTrue(fileTest.createNewFile());
//            assertTrue(fileTest.exists());
//            assertFalse(fileTest.renameTo(fileExistentFolder));
//
//            // Return FALSE with fileNonExistentFoler,
//            // and create a new file for fileNonExistentFoler
//            assertFalse(fileTest.renameTo(fileNonExistentFoler));
//            assertEquals("Test", fileTest.toString());
//
//            // Create a destination fileNewTest
//            File fileNewTest = new File("NewTest");
//
//            // Make sure the fileTest is Existent, fileNewTest is non-existent
//            assertTrue(fileTest.exists());
//            assertFalse(fileNewTest.exists());
//
//            // Return TRUE. The fileTest was moved into fileNewTest
//            assertTrue(fileTest.renameTo(fileNewTest));
//            assertFalse(fileTest.exists());
//            assertTrue(fileNewTest.exists());
//
//            // Delete file after testing
//            fileNewTest.deleteOnExit();
//            fileNonExistentFoler.delete();
//    }
//
//    @Test
//public void test36FileToString() {
//        File fileTestFolder = new File (TestJavaIoFile.pathTestFolder);
//        assertEquals(TestJavaIoFile.stringPathTestFolder.toString(), fileTestFolder.toString());
//    }
//
//    @Test
//public void test37FileToUri() throws URISyntaxException {
//
//            URI uri = new URI(TestJavaIoFile.pathUri);
//
//            File fileUri = new File(uri);
//            assertEquals(TestJavaIoFile.stringUriPath.toString(), fileUri.toString());
//            assertEquals("file:/E:/Users/admin/test.txt", fileUri.toURI().toString());
//    }
//
//    @SuppressWarnings("deprecation")
//    @Test
//public void test37FileToUrl() throws URISyntaxException, MalformedURLException {
//            URI uri = new URI(TestJavaIoFile.pathUri);
//
//            File fileUri = new File(uri);
//            assertEquals(TestJavaIoFile.stringUriPath.toString(), fileUri.toString());
//            assertEquals("file:/E:/Users/admin/test.txt", fileUri.toURL().toString());
//    }
//}
