 /*
 * FreeRTOS V202002.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

#ifndef AWS_CLIENT_CREDENTIAL_KEYS_H
#define AWS_CLIENT_CREDENTIAL_KEYS_H

/*
 * PEM-encoded client certificate
 *
 * @todo If you are running one of the FreeRTOS demo projects, set this
 * to the certificate that will be used for TLS client authentication.
 *
 * @note Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----\n"
 */
#define keyCLIENT_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDWjCCAkKgAwIBAgIVAMf6IPQ4dy45Tcnz2qBS+5x4rRieMA0GCSqGSIb3DQEB\n"\
"CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n"\
"IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMDAyMTQwODE3\n"\
"MTRaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n"\
"dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC/HJjrqtSbyEBMfc0v\n"\
"FdaFFO2e0iIQLYMs51IEsA12Z8VnCoNO8Tv0PmzrCoB0ysS4uQfXAyG/TIqxzf7q\n"\
"THuzS3dx48MYvNSbABt5bJ+R19nQSnrudJMUEa3lcbprZT+tysgZWOBVoRoJyx4Y\n"\
"OKzOTObGLphvvgQbSGVxCRyQzLILW6B4zmvKZHhDkIad6immgOnrd79xSawjky0O\n"\
"huLeDumoRG15bI+/9Lztq7zlQoEMWOGIgwpeviePIor6uO4qQbbavVkQR0LGRo/3\n"\
"Rjr5cdXadqeOHw3DlglYfAqWFVrfCbzE1lYqmWcbyde9U3Uk0Ywq675FaULJ7ALM\n"\
"X7SjAgMBAAGjYDBeMB8GA1UdIwQYMBaAFHQyoBaJi9f8K0l9jRaXCni76h42MB0G\n"\
"A1UdDgQWBBTOqWReTFy9Cr7G0wnmPmPsAFjl5TAMBgNVHRMBAf8EAjAAMA4GA1Ud\n"\
"DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAJP/v30jlwrm6zRPtFDdwI3CP\n"\
"oQrvMJVayFeFXUxw2joLEJQFS+IyxSxs3eKiNFl5xyqDJkxc5rnOzARJsQ5xhMB/\n"\
"6bs82W7eC0mWVd6Sps7uK5APHhWI8bX06FaPGamLkrtzMrfk3mTTZ8v3FrRJkJay\n"\
"7GrhZMl45MMMX5DyPOsuCetFvvIR95aQvX3L398JwqM0oAq+4QYGoUWgTvtG0V1J\n"\
"zMfNqDiWMf4qMyBKf9SbmdDi6eMjBwCDlqsgkTwMUeaYsEc0eGFQZq2YLFsIkRP6\n"\
"j2qEX7XaQXiaVp2BnSaUzoElBw8OFRFL0+DNVrAd56cPRdx3EIL9/I4q+tGXzw==\n"\
"-----END CERTIFICATE-----\n"

/*
 * PEM-encoded issuer certificate for AWS IoT Just In Time Registration (JITR).
 * This is required if you're using JITR, since the issuer (Certificate 
 * Authority) of the client certificate is used by the server for routing the 
 * device's initial request. (The device client certificate must always be 
 * sent as well.) For more information about JITR, see:
 *  https://docs.aws.amazon.com/iot/latest/developerguide/jit-provisioning.html, 
 *  https://aws.amazon.com/blogs/iot/just-in-time-registration-of-device-certificates-on-aws-iot/.
 *
 * If you're not using JITR, set below to NULL.
 * 
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----\n"
 */
#define keyJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM  NULL

/*
 * @brief PEM-encoded client private key.
 *
 * @todo If you are running one of the FreeRTOS demo projects, set this
 * to the private key that will be used for TLS client authentication.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN RSA PRIVATE KEY-----\n"\
 * "...base64 data...\n"\
 * "-----END RSA PRIVATE KEY-----\n"
 */
#define keyCLIENT_PRIVATE_KEY_PEM \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEpAIBAAKCAQEAvxyY66rUm8hATH3NLxXWhRTtntIiEC2DLOdSBLANdmfFZwqD\n"\
"TvE79D5s6wqAdMrEuLkH1wMhv0yKsc3+6kx7s0t3cePDGLzUmwAbeWyfkdfZ0Ep6\n"\
"7nSTFBGt5XG6a2U/rcrIGVjgVaEaCcseGDiszkzmxi6Yb74EG0hlcQkckMyyC1ug\n"\
"eM5rymR4Q5CGneoppoDp63e/cUmsI5MtDobi3g7pqERteWyPv/S87au85UKBDFjh\n"\
"iIMKXr4njyKK+rjuKkG22r1ZEEdCxkaP90Y6+XHV2nanjh8Nw5YJWHwKlhVa3wm8\n"\
"xNZWKplnG8nXvVN1JNGMKuu+RWlCyewCzF+0owIDAQABAoIBAQC0ineMax3e7RaR\n"\
"LGciDCdUIak5WJoFXnmFeiHpe8e8C9xYs33InexdmHucr5cavlOJjoLxhGvlJJIB\n"\
"1vDytr5Faw2z8c7lF75hj4Bk/VDhnmCOfU4U5tvrIah+ESpjOosly2OtTmDfhAnt\n"\
"Jo2PpDrbyZpZrrsjFQccHxB18H2j65nS2839Palw2PMmzt+xtAIijduBorgwUU+m\n"\
"QgWkw06bCPHWc2tfRouxhsKsKuh83KMuNMFiECWv/aVdMbur7tWB9jC30ll7ivOv\n"\
"gdgJhBMnnJjd9vON6cpi2lpDXvZhEZrdrHPm/9Fa0dNi6ZN+uF5lo27YGQk7EPUS\n"\
"rE51+wfBAoGBAOoEh0Bx2A/BXVfeFs0FGKX6DqsWyj9nFk5fz4/0PR4UyW+RPwuO\n"\
"Jw09eqjT/EqYovd0dMgnNCOqRVX3q9ttl8xkhO9vahxWyypsoo574Yojq+X7HJdw\n"\
"Oe/9WLLSqy9VgTdLGwIPIUsv3if/UNEc3GkWYF3iJvr5k8S/zjO1qGqPAoGBANEQ\n"\
"TNAg2SfxEZAjksWrIQVZna+7chUVC1+m6YGeb4f+VRH1heu3Q1jtxpLIFsRFQieZ\n"\
"18udo2trDi6qMK/CaN/xBdcB/P6LWp9FJEnx1T1whM1Twh+1xcn/pUBvaokEaFvh\n"\
"tF7//Ns8NxHF6sJAOLzffsIAW9SDdtGujCgP9i6tAoGAKzh64mQkS4SjAL975pGy\n"\
"Y7UzUFX9NIiNjhwT8bpiL1QXgAuLYU7313IrXVMJnZ1jO+C+UNkswAmKlL4Rd41e\n"\
"I9nM04v4RROioks+GqK2nRTJgshGF5IaoUBhSWWvSCa6nsO4UUEKHSDSHwEApB54\n"\
"dtAzLCPAn0nJCOWD5/j9CfECgYAJp/oURuAg0yafhLUbwiq1R41b94luZdlvopL4\n"\
"dKvsGRguyytTVtSaf+kDEJDUoepLT/TCp9ZLeNdf2maDR7R2W3iMlL/ttdwKrTPe\n"\
"4neZ7d+EaFD4C/pFuTQVxM+j4ns7ezJMjQBN0/srK/wK2tKEDsKZDVEwgJ31U12P\n"\
"4CTbxQKBgQDOoMvCD0bX0R8Kbb2ibJNYMJ7tD8+rWkGQ0gesziIB0Y8GaLAxsaUV\n"\
"SxaeHdKNViOe1u2I1dwqfS6GzaIh8AQo8TsE87xoW04+dm0QYSNr+sq7esHhhb2v\n"\
"JMqYRs7V9+Ha5jGYHT0+xAdj98OvQAdTV5Ep9V9qdTLUR4llElGfnQ==\n"\
"-----END RSA PRIVATE KEY-----\n"


#endif /* AWS_CLIENT_CREDENTIAL_KEYS_H */
