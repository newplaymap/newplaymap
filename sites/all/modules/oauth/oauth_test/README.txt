// $Id: README.txt,v 1.1.2.1 2008/11/11 03:28:53 brmassa Exp $

OAUTH TEST
==========

This module purpose is to provide a basic blueprint for developers who
want to integrate their modules with Web Services that use OAuth as the
authentication system.

As a generic module, its designed to include several options for developers,
but generally many of these options might be hardcoded on the real modules
because Web Service providers have specific values.

We assume that you are familiar to OAuth/Web Services jargon.

The code is well commented but feel free to bring any questions or suggestions
to OAuth module's issues list (http://drupal.org/project/issues/oauth).


CUSTOMIZING
===========

When reusing the module's code for your own module you will need:
1* Rename the module's functions
2* Rename the module's database tables
3* Remove all non-used server types. Web Services providers generally only
   use only type: XML-RPC, REST, SOAP... you dont need all these alternatives
   on your code
4* Hardcode all provider-specific values, like URLs, signature method, etc.
   The only option that should be on a settings page is the consumer keys and
   secret, that varies to user to user.
5* ... enjoy!
