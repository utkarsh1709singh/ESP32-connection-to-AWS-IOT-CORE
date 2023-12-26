#include <pgmspace.h>

#define SECRET
#define THINGNAME "MyNewESP32"

const char WIFI_SSID[] = "Utkarsh";
const char WIFI_PASSWORD[] = "12345678";
const char AWS_IOT_ENDPOINT[] = "a3k8n41tipl8ay-ats.iot.ap-south-1.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAPX3ro6fRyqDT9jd7TL+Qo5nAatnMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzExMTkwOTE1
MjlaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCtF0kplGMcJu4qkS3v
kPYbPe5P9EGpmrMKRrBqfWPFM5xlaAZ/WNHxCWUFy1AQGAK8CZVvXNt2uDpJUcNT
vG5WxpI57oNQQsBXDAGHn4GczrpYFBP+7gXlJs3z71Va713KYcvg5yYEWCE+PTfK
GNJ8FH1qWlhXPMH9LAOPQd/bE+Khe6UURyvLubv/Jm2SwqZsFstiW3KJEc1gyY4y
lDebcytEm1mW45e0eiSgMXl59KMJmMQRjJpYT8r71X8COuh0Jucn3XQVg+kBPGQx
gtEGFnRs4hSxE0hYY+rANDCnYp4J6pkQHq7vkGHBfvctfJIrOy4vGGlEMPsx3lFM
LbZJAgMBAAGjYDBeMB8GA1UdIwQYMBaAFPqycfHwZ/yWMLKCB+JyKRZPyxoIMB0G
A1UdDgQWBBSLo3wUn8U1UnHs9JB+eF/+MNaHUTAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAdGC0JCuhM+yZ7YesVZCnLQ9Y
+/qRlZay1KaQSj7x2TLfV1Hj+UNm2trmAznIJMS4OuAZJ6JDRMsMIA392ANVr/jf
RVqCAZj5Bcj/tu0bpi2WyV18EIooxnxWPKHGi5XMvAGNp6drDBODc2zLHIrbHXw1
tUSUD4bbHJUdezz+PawriWz2NJBqy8SKBe6IqKstKsbZYDq5u5SR1xfyUCf5e5Xq
jf+GIxjGZ2SkpwlULPxI02Nobh4rzhA0XBoVywbCIRzN7B+Eu14j0uB3Zkk2kuiE
qFbhL3RoVYvg58jbVeQAA935yT1oevraxL/X32GwHHanUfeWjj1Jlmb5UZsTMw==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEArRdJKZRjHCbuKpEt75D2Gz3uT/RBqZqzCkawan1jxTOcZWgG
f1jR8QllBctQEBgCvAmVb1zbdrg6SVHDU7xuVsaSOe6DUELAVwwBh5+BnM66WBQT
/u4F5SbN8+9VWu9dymHL4OcmBFghPj03yhjSfBR9alpYVzzB/SwDj0Hf2xPioXul
FEcry7m7/yZtksKmbBbLYltyiRHNYMmOMpQ3m3MrRJtZluOXtHokoDF5efSjCZjE
EYyaWE/K+9V/AjrodCbnJ910FYPpATxkMYLRBhZ0bOIUsRNIWGPqwDQwp2KeCeqZ
EB6u75BhwX73LXySKzsuLxhpRDD7Md5RTC22SQIDAQABAoIBAQCVqrjcdy5rvU3b
CMXLjHEBhT93ayEL4nRFwnHw4pNOhR4KoTRdERQXc6QiqnaEM/7JURAhxw0NTqc3
lrdqxFg0OGdgKFjrIYzmt77q4oVUbXy7hED2AiKezjrvXldT1f4nbQC5a6V3xCya
gJyo52W5XI5FU/FnHWYv38sEKFXEO7VflDQ2kmkCrfde5byzgs/RizpIauFW3uGH
ee2rFwlWJNL2KbIY30jPbaAGDiIAa5WQUkPntBUSiolvVimFMey+jLyy7ys9+xqV
VJsXvhuK4lpsbLTJRF41YaoIwoJuRakpuyQgHeOXBckoM7PP+9dDm5oqzeGXYU6W
4/YPx9cxAoGBANidWbO9AkQC/VNk69Twl7KGUzVJ++IfbLqlzgZtopR0hx4eL4p6
H1nDkP1iuGw8KXq3d0Jx7XljitRr4xgtLOlPd1G3lWMeqvJzCE13g8DllMfPMvOQ
bZMQNtZIQkkzSRJjmk3LjY4qzX6kyhBrnHoNP48EwhgvVesz8s9/SFjHAoGBAMyQ
D5D6bk5Ybz1f7fZk1wB0ZWfIcZcXOc6PIPLP9qitGfHQgzoO3UeUCYT4tMX6rIBl
LXe/kdf6GhLeqY6W6fS7lUboO1plbSLKDjY4pQppjj7F4EZX2K+5+4jB1NU3mbg/
4/27bF/m0TvrAoM/ESh5HahsrCqRePf+ahWPrwhvAoGAA6OZFzDssdHPCbCfWaN1
GPWyvilxBtp6TCRu8qKy4YWXo4TkTZJBppNngyo+aOsV007zvPUHBUwL0AfD9+sC
XyULnx7TbqfcPVh7YjnIx9vThQvRElBx1s+l7DGok2w+JQXxWK87wJCthRwlnOMB
7Pb+A1wUGq3o5punz56Wy48CgYAsPrCPPAtluKz+ymPu2irCt2pDg1BGTMi9C6ol
uqNwIlitO9tWUGa+F5/jeeOnuqta7gdikjXaUAcZs71a0PtzaqtD9fD4gV2Um71t
Lt1Lnj8dBrGWpWOBxqlIEByXrXn7Jx6J/+LV71esLQ2TE64DYgbvKeonHuXaRdXu
KfDC0wKBgQCFcs4IfSxXlurqG+AhGFSElcldi/4nyqACEWh1TpCMv82JNZ9BmF22
RwtQbz+LzWhUYiIIo9Qcw0Q8QUfL+0s+HpfIElbd3JwGkquSYWMhmQdMFzyVJOVH
8aKcJPrAm8DBve+wCH08qmFS49UE0mKQZ9rKNitsBTD0GsRGFSazUQ==
-----END RSA PRIVATE KEY-----
)KEY";