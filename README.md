# ft_ssl
42 project that requires recoding in C, from scratch, the md5 and sha256 one way hash functions

## resourcer
md5 : https://www.ietf.org/rfc/rfc1321.txt

sha256 : https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf

## compilation
for compilation, just go to project directory and run :
```bash
make
```
that would result an executable "ft_ssl"

## usage examples

```bash
$ ./ft_ssl
./ft_ssl [COMMAND] [-pqr] [-s string ...] [file ...]
```

```bash
$ ./ft_ssl md5 testfile
MD5 (testfile) = c4fc7be13f475dd7555d2113140e1b27
```

```bash
$ ./ft_ssl md5 -s "teststring"
MD5 ("teststring") = d67c5cbf5b01c9f91932e3b8def5e5f8
```

```bash
$ ./ft_ssl sha256 helpfile
SHA256 (helpfile) = 8aac6b9f0bd6b2aef4b5bd20c4c175138f03e94b2f5506f18f3d3a64eba55a5a
```
```bash
$ ./ft_ssl sha256 -s "help"
SHA256 ("help") = 106a5842fc5fce6f663176285ed1516dbb1e3d15c05abab12fdca46d60b539b7
```
