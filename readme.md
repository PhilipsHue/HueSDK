# This repository is deprecated.

**Deprecation – Philips Hue SDK**

We have decided to **deprecate the hue SDK** effective **as of July 1st 2019**. This means there will be no new SDK releases except for critical updates (e.g. security) which will be maintained for one additional year. Existing Hue SDK client applications will continue to work normally but we can no longer guarantee long term compatibility with future Hue software. We strongly recommend Hue SDK users to migrate to Hue API which remains up-to-date and supported.

**FAQ**

**Why is this changing?** Philips Hue has decided to focus its resources into improving the Hue API and building new features. The usage of the SDK has been declining as has our own dependence on it so we feel it is more beneficial to focus on building directly on the Hue API.

**Who’s Impacted?** Anyone who is leveraging the Philips Hue SDK.

**Who’s Not Impacted?** Anyone who is not utilizing the Philips Hue SDK.

**What should you use instead?** Philips Hue API

**Next steps?** Migration code samples and best practice blogs by Hue Developer Program.

**Question?** Contact us! https://developers.meethue.com/support/

**See also:** https://developers.meethue.com/deprecation-philips-hue-sdk/

-----

# Hue SDK

Building a Smart Home app? A well designed SDK should make your application development life easier, giving you the tools and documentation to easily add new functionality to your application. The new Hue SDK deliver just that. We designed them with cross-platform in mind, to allow you to quickly integrate key Hue functionality when you need it, used either together or separately. Hue SDK is a new set of development tools that are designed to access the Hue system through Hue bridge and control an associated set of connected lamps. The aim of the SDK is to enable you to create your own applications for Hue system.

To develop for Hue you require the Philips Hue Personal Wireless Lighting System.

## Supported platforms
Hue SDK provides a Java and an Objective-C API to access Hue system and is available and supported on the following platforms:

### Java API:
* Android, API 19 and higher
* Windows 10 (x86_64)
* Ubuntu 16.04 (x86_64)
* macOS 10.9 and higher

### Objective-C API:
* iOS 8.0 and higher
* WatchOS 2.0 and higher
* TvOS 8.0 and higher
* macOS 10.9 and higher


## Get Started
To start app development with Hue SDK you can download iOS or Java/Android QuickStart App and use them as your base, with documentation and guide included. The source for these are both hosted in github and can be found here:

* iOS Quick Start App:

  Example app using Objective-C to discover, connect, and authenticate to a Hue bridge and then update lightstates.

* Swift Quick Start App: 
    
  Example application developed in swift which also uses the Objective-C wrapper to perform similar tasks like iOS Quick Start App.

* Java/Android Quick Start App:
    
  Another example application using Java wrapper to perform similar tasks like iOS Quick Start App.

## Help and Support
Stuck, need help or any suggestions on how to improve Hue SDK? For now please raise an issue in Github and one of Hue developers will reply shortly.

## Acknowledgements
Please adhere to any third party licenses that are applicable on this SDK when building applications with our SDK or using the QuickStart applications as your base
(see the HueLicense.txt and OSSlicenses.txt files in our repository, for applicable licenses).
