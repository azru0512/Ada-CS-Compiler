/** \page autotools Autotools
 *
 * 稍微了解 Makefile 有助於後續工作。請見<a href="http://tetralet.luna.com.tw/index.php?op=ViewArticle&articleId=185">Makefile 語法簡介</a>。本計劃採用 Autotools 來建置系統。請見<a href="http://tetralet.luna.com.tw/index.php?op=ViewArticle&articleId=200&blogId=1">利用 Autotools 來建立 Makefile 檔案</a>。 執行根目錄底下 autogen.sh 會依序呼叫 libtoolize aclocal autoconf automake 產生 Makefile 和 configure。
 *
 * <a href="http://www.gnu.org/software/hello/manual/autoconf/">Autoconf</a> 裡跟本計劃有關的章節。
 * - <a href="http://www.gnu.org/software/hello/manual/autoconf/Particular-Programs.html#Particular-Programs">5.2.1 Particular Program Checks</a>
 *
 * <a href="http://www.gnu.org/software/hello/manual/automake/">Automake</a> 裡跟本計劃有關的章節。
 * - <a href="http://www.gnu.org/software/hello/manual/automake/Subdirectories.html#Subdirectories">7.1 Recursing subdirectories</a>
 * - <a href="http://www.gnu.org/software/hello/manual/automake/Program-and-Library-Variables.html#Program-and-Library-Variables">8.4 Program and Library Variables</a>
 * - <a href="http://www.gnu.org/software/hello/manual/automake/Program-Variables.html#Program-Variables">8.7 Variables used when building a program</a>
 * - <a href="http://www.gnu.org/software/hello/manual/automake/Yacc-and-Lex.html#Yacc-and-Lex">8.8 Yacc and Lex support</a>
 * - <a href="http://www.gnu.org/software/hello/manual/automake/C_002b_002b-Support.html#C_002b_002b-Support">8.9 C++ Support</a>
 *
 * 參考文件:
 * - <a href="http://www.gnu.org/software/hello/manual/autoconf/">Autoconf</a>
 * - <a href="http://www.gnu.org/software/hello/manual/automake/">Automake</a>
 * - <a href="http://sourceware.org/autobook/">GNU AUTOCONF AUTOMAKE, AND LIBTOOL</a>
 *
 */
