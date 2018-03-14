# meta-string

Tiny project using constexpr to concatenate string literals at compile-time reducing it to (roughly) 2 mov's per additional string.  
   
Compiler Explorer assembler output: [link](https://godbolt.org/#z:OYLghAFBqd5QCxAYwPYBMCmBRdBLAF1QCcAaPECAKxAEZSAbAQwDtRkBSAJgCFufSAZ1QBXYskwgA5NwDMeFsgYisAag6yAwskEF8qDdg4AGAIJyFSlZnVa8qXcUxMAtoZPmzAei8BafwGBQcEhoWHhEZEeBJguAA7MMbaauuggIIJ4AF6YAPoEqgDKAFruZkpMgoKquYUExArAADKEmMRMDB4cAOx8ZqqqyAhMxKouuSPtAJ4cAKw8JXMAIrYrPXzdSxp9nqZxIgBGDHjIIB4DaCy6mAAecaO19Y0tMe0MEJe6g8OjENwAbMdXh0AJRzBalWZLMH9dS9c4DVQAMxIqggqXSmRy%2BVUeFWqmM21xySKpVkPHUvH4eBhpkRcJ29IG40mTBm8zwy3xQLaHXBnKh2wRAx6W1hoq6sJi8USNg0KT0mOyeQKTRKpFUGIyypxACVFrIjLDPjE7g86g02C9ee9hYNUFcCo9Lc1Wm95WqyUYuP9NfR7Y6ahbnm6%2BVp9V6AZquLSRfDYRcHV8tViVaoGAhBNgWOh8Z7VL5VLQiYifKoAHI8EAF2iqIiqJwuVAANxsLBEDAYdbaLgUTCIxDtKN%2BKZ1BTxGhWhPJxPl6cz2fQRP41NjiPWduZE2I035XMnfr3gvJdolZiHqPRiu12PH%2BOnFInWlUEeXVN4NNP8bpTJZO7Z4IZlmOaUo%2B%2B6yCsghcEeWwngmcJij%2BZ67Imjq3Pc3wjKoqBxLyA7gssV5pDeaY0gGXwsKgtwSHEBAIhu8FOAQYgsGiT6aKSIK2AAYmM267hyXLVg%2B9GbJKP4muhoyjremrKhAXEmqolHUZgtEMg2mDMcQrEQCUqhgGAB7GFxGi8fpha1sJy5ieexpJqaGFKUMIwAFSDLkjgKeRBQqTcNEFOsmnaaxf67jOyESnBuw%2BJEcXxQliWhNEsQJP2cpaDJablv6WU4uW0GGh4klmqoTAiEQHg4XhJD8B8DlBk8Vqhp0Wg5e4Pp%2BhqSnOiGwKtZoBUdb6UFrr4hiNS61rum1tb8BWXAFkWZTmN%2BAxMSxk19Ta8o5aBC1LcWhrorlMZCuetkxX4SU3bdd0BB4ZZLJg6AiMgBD2KxCCYAwuGjEiIiKB9DrIqiACyhQAGocR8zBVN2MrpaoWCve9n2ah9nZjHgVSNLS0ppUk8p5QUBpGqYJUYeVlVmMGzX9fVgYub8AI8m8YLzIsUJceNhpbfTO1aGTXRrcFm29QLM2aGTEBs6C52rYhj3Xfdqtq%2BEHgKHRZguEwCgKSLjI%2BVJZUVagfr4nTroM9wXAABI/QwqAarbYLRah1yldT5tQZbTXWzafxcFwADqJAMOghmuwrHuOaM3uarIftTS1QeLRATDAHrLBgsHbs7AilPx2bmqaCDB6CHNvDRvtgiyDHGPEWgFXJHOghlywAB0yCefUBvRQiG06QSCuRd4Kvq5PU8eFIIKMNIsxSKQLDSMYS%2BoNImgrtXwhiBIlKyLQS8EKvs9zwA1iAsgACyd7QAAcN%2ByAAnM/9/X/83T/K/1/z1I19LxcHQYwxhl6n1IBvKQS9BAgFASfKQa855wFgEgNA8Q8AMDaOQSgaC4gYLaCAYA3RZCkCRBg14MCIC5GocYSgc8DjgIOH2YgUxpBH1IGglwmAWAEAAPIsAYKwhBS8sC6zYJg8B%2BAnBo1bDA4RpBbiYGQBVSQUh2Fax%2BuAqgABHEQbQhGyE7lwO%2BS9MFsAIEgeg9xMDNl4QcKgSiT5UJoZQLEWRMG0FmMYa%2B3Rn4gO6MYQ%2BXBKCAywGQlgL1KCYOANwtIkBZikFAWos%2BII55mOABYugpBrG2PsY4yg1Dci0OoAART0Sw2QXBaDGHvs/f4xguC%2BNmC/a%2Bsxn7EKqZQfAgg0pCNnkIbI7jMCeO8b4/xgTaDBIgKEzA4TImy0wDEnM8AElJKPqk1JjBuEZMsZsp4QDklpNYOwbeAhjgHBgZAOeOFgZXGkL4VIk5ODvh4LQboBZeFcGgaIcQkhaBpIXkvFe8jIE3Hvv8Xw/xr6qGAMgZAqhuidyThAXAhBURyH9GXdBmDRgYq4lvF5x9T6bO%2BkwLAxA6GkEvlwZ%2BndfFcHvrMe%2BtBaCyGac/YOCSGDSAAaQIB1TQHArXhA6Q0DYGkHgYg0gyDEAgFEAQfYBBsH1WxQQ%2BgL00UUv%2BX/ReYCQXSAxaoAA7oQBAqgwUQqhTCuFCKkVEuEZsy%2Bsh/idwabIAJtA/FvMfsyv%2BvKhXr1FUIcVkqz5/y%2BXq4VkD7WILnq2YgmQHQgGvkAA%3D%3D%3D)

## Building:
+ On Windows run the provided `build.bat` file  
   
+ On gnu tools run `build.sh`  
   
+ Or type the following commands:  
   `mkdir build && cd build`  
   
   `cmake ..`  
     or to use your specific compiler:  
   `cmake .. -DCMAKE_CXX_COMPILER=g++-7.1`  
   
   then finally:  
   `cmake --build .`  

## Requirements:
+ A compiler with some C++ 14 support (i.e. extended constexpr support)  
    (Tested on VS 2017 15.6 and GCC 7.1) 

+ CMake 3.9.2 or higher
