########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 1/20/2018
#
# Thirdpary Makefile for crono
########################################################################

########################################################################
#
# crono defs
#
########################################################################
CRONO_MAKEDIR=$(PWD)

CRONO_THIRDPARTY = $(CRONO_MAKEDIR)/..
#CRONO_BUILD_HOME = $(CRONO_THIRDPARTY)

ifndef CRONO_UNAME
CRONO_UNAME = $(shell uname)
endif

ifndef CRONO_OS
ifneq ($(CRONO_UNAME), Darwin)
CRONO_OS = linux
else
CRONO_OS = macosx
endif
endif

#
# crono version
#
CRONO_VERSION_MAJOR = 0
CRONO_VERSION_MINOR = 0
CRONO_VERSION_RELEASE = 0

CRONO_VERSION_SEPARATOR = .
CRONO_VERSION_MAJOR_SEPARATOR = $(CRONO_VERSION_SEPARATOR)
CRONO_VERSION_MINOR_SEPARATOR = $(CRONO_VERSION_SEPARATOR)

CRONO_VERSION_SHORT = $(CRONO_VERSION_MAJOR)$(CRONO_VERSION_MINOR)$(CRONO_VERSION_RELEASE)
CRONO_VERSION = $(CRONO_VERSION_MAJOR)$(CRONO_VERSION_MAJOR_SEPARATOR)$(CRONO_VERSION_MINOR)$(CRONO_VERSION_MINOR_SEPARATOR)$(CRONO_VERSION_RELEASE)

#
# crono name
#
CRONO_NAME_SEPARATOR = -
CRONO_NAME_BASE = crono
CRONO_NAME = $(CRONO_NAME_BASE)$(CRONO_NAME_SEPARATOR)$(CRONO_VERSION)
CRONO_INSTALL_NAME_SEPARATOR = -
CRONO_INSTALL_NAME = $(CRONO_NAME_BASE)$(CRONO_INSTALL_NAME_SEPARATOR)$(CRONO_VERSION)
CRONO_DIR = $(CRONO_NAME)

#
# crono archive
#
CRONO_ARCHIVED = tar
CRONO_COMPRESSED = gz
CRONO_ARCHIVE_SEPARATOR = .
CRONO_ARCHIVED_SEPARATOR = $(CRONO_ARCHIVE_SEPARATOR)
CRONO_COMPRESSED_SEPARATOR = $(CRONO_ARCHIVE_SEPARATOR)

CRONO_EXTRACT_DIR = $(CRONO_NAME)
CRONO_TGZ_PREFIX = 
CRONO_TGZ = $(CRONO_NAME)$(CRONO_TGZ_PREFIX)$(CRONO_ARCHIVED_SEPARATOR)$(CRONO_ARCHIVED)$(CRONO_COMPRESSED_SEPARATOR)$(CRONO_COMPRESSED)
CRONO_PATCH_TGZ_PREFIX = $(CRONO_NAME_SEPARATOR)patch
CRONO_PATCH_TGZ = $(CRONO_NAME)$(CRONO_PATCH_TGZ_PREFIX)$(CRONO_ARCHIVED_SEPARATOR)$(CRONO_ARCHIVED)$(CRONO_COMPRESSED_SEPARATOR)$(CRONO_COMPRESSED)
CRONO_DOCS_TGZ_PREFIX = $(CRONO_NAME_SEPARATOR)docs
CRONO_DOCS_TGZ = $(CRONO_NAME)$(CRONO_DOCS_TGZ_PREFIX)$(CRONO_ARCHIVED_SEPARATOR)$(CRONO_ARCHIVED)$(CRONO_COMPRESSED_SEPARATOR)$(CRONO_COMPRESSED)

#
# crono extract
#
ifeq ($(CRONO_ARCHIVED),tar)
ifeq ($(CRONO_COMPRESSED),gz)
CRONO_TAR_UNCOMPRESS = z
CRONO_TAR_COMPRESS = z
else
ifeq ($(CRONO_COMPRESSED),bz2)
CRONO_TAR_UNCOMPRESS = j
CRONO_TAR_COMPRESS = j
else
ifeq ($(CRONO_COMPRESSED),xz)
CRONO_TAR_UNCOMPRESS = J
CRONO_TAR_COMPRESS = J
else
endif
endif
endif
CRONO_LIST = tar -tv$(CRONO_TAR_UNCOMPRESS)f
CRONO_EXTRACT = tar -x$(CRONO_TAR_UNCOMPRESS)f
CRONO_ARCHIVE = tar -cv$(CRONO_TAR_COMPRESS)f
else
ifeq ($(CRONO_ARCHIVED),zip)
CRONO_LIST = unzip -l
CRONO_EXTRACT = unzip
CRONO_ARCHIVE = zip
else
CRONO_LIST = echo unable to list
CRONO_EXTRACT = echo unable to extract
CRONO_ARCHIVE = echo unable to archive
endif
endif

CRONO_LIST_TGZ = $(CRONO_LIST) $(CRONO_TGZ)
CRONO_EXTRACT_TGZ = $(CRONO_EXTRACT) $(CRONO_TGZ)
CRONO_TOUCH_EXTRACT = touch $(CRONO_DIR)
CRONO_REMOVE_DIR = $(CRONO_REMOVE) $(CRONO_DIR)

CRONO_LIST_PATCH = $(CRONO_LIST)
CRONO_EXTRACT_PATCH = $(CRONO_EXTRACT)
CRONO_LIST_PATCH_TGZ = $(CRONO_LIST_PATCH) $(CRONO_PATCH_TGZ)
CRONO_EXTRACT_PATCH_TGZ = $(CRONO_EXTRACT_PATCH) $(CRONO_PATCH_TGZ)

CRONO_LIST_DOCS = $(CRONO_LIST)
CRONO_EXTRACT_DOCS = $(CRONO_EXTRACT)
CRONO_LIST_DOCS_TGZ = $(CRONO_LIST_DOCS) $(CRONO_DOCS_TGZ)
CRONO_EXTRACT_DOCS_TGZ = $(CRONO_EXTRACT_DOCS) $(CRONO_DOCS_TGZ) -C$(CRONO_DOCS_PREFIX)

#
# crono build
#
ifndef CRONO_BUILD_HOME
CRONO_BUILD = $(HOME)/build
else
CRONO_BUILD = $(CRONO_BUILD_HOME)/build
endif
CRONO_PREFIX = $(CRONO_BUILD)/$(CRONO_INSTALL_NAME)
CRONO_EXEC_PREFIX = $(CRONO_PREFIX)
CRONO_CONF_PREFIX = $(CRONO_PREFIX)
CRONO_DOCS_PREFIX = $(CRONO_PREFIX)
CRONO_LINK_NAME = $(CRONO_BUILD)/$(CRONO_NAME_BASE)

CRONO_MKDIR = mkdir -p
CRONO_REMOVE = rm -r -f

CRONO_MAKE_DIR = $(CRONO_DIR)
CRONO_MAKE_PUSHD = pushd $(CRONO_MAKE_DIR)
CRONO_MAKE = make

#
# crono configure
#
ifneq ($(CRONO_UNAME), Darwin)
CRONO_CONFIGURE_UNAME = 
else
CRONO_CONFIGURE_UNAME = 
endif
CRONO_CONFIGURE_CONFIGURE = ./configure
CRONO_CONFIGURE_HELP = $(CRONO_CONFIGURE_CONFIGURE) --help
CRONO_CONFIGURE_PUSHD = pushd $(CRONO_MAKE_DIR)
CRONO_CONFIGURE = $(CRONO_CONFIGURE_CONFIGURE) \
$(CRONO_CONFIGURE_UNAME) --prefix=$(CRONO_PREFIX) --exec_prefix=$(CRONO_EXEC_PREFIX)

#
# crono help
#
CRONO_HELP = $(CRONO_CONFIGURE_HELP)

########################################################################
#
# rules
#
########################################################################

all: build

package: archive unextract

again: unextract build

test: test-crono

install-links: install-crono-links

install-docs: install-crono-docs

install-prefix: install-crono-prefix

install: install-crono

build: build-crono

clean: clean-crono

configed: configed-$(CRONO_DIR)

config: config-$(CRONO_DIR)

help: help-crono

list-docs: list-crono-docs

list-patch: list-crono-patch

extract-patch: extract-crono-patch

list: list-crono

extract: extract-crono

unextract: unextract-crono

archive: archive-crono

linked: crono-linked

prefixed: crono-prefixed

archived: crono-archived

extracted: crono-extracted

########################################################################
#
# crono rules
#
########################################################################

#
# Help crono
#
help-crono: $(CRONO_DIR)
	@($(CRONO_CONFIGURE_PUSHD);\
	  (($(CRONO_HELP)) || (exit 1));\
	  popd)

#
# Install crono
#
install-crono: configed-$(CRONO_DIR)
	@(echo Installing $(CRONO_DIR)...;\
	  $(CRONO_MAKE_PUSHD);\
	  (($(CRONO_MAKE) install) || (exit 1)) && \
	  ((touch $(CRONO_MAKEDIR)/configed-$(CRONO_DIR)) || (exit 1));\
	  popd)
	  
#
# Build crono
#
build-crono: configed-$(CRONO_DIR)
	@(echo Building $(CRONO_DIR)...;\
	  $(CRONO_MAKE_PUSHD);\
	  (($(CRONO_MAKE)) || (exit 1)) && \
	  ((touch $(CRONO_MAKEDIR)/configed-$(CRONO_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean crono
#
clean-crono: configed-$(CRONO_DIR)
	@(echo Cleaning $(CRONO_DIR)...;\
	  $(CRONO_MAKE_PUSHD);\
	  (($(CRONO_MAKE) clean) || (exit 1)) && \
	  ((touch $(CRONO_MAKEDIR)/configed-$(CRONO_DIR)) || (exit 1));\
	  popd)
	  
#
# Test crono
#
test-crono: configed-$(CRONO_DIR)
	@(echo Building test $(CRONO_DIR)...;\
	  $(CRONO_MAKE_PUSHD);\
	  (($(CRONO_MAKE) test) || (exit 1)) && \
	  ((touch $(CRONO_MAKEDIR)/configed-$(CRONO_DIR)) || (exit 1));\
	  popd)
	  
#
# Config crono
#
config-$(CRONO_DIR): unconfig-$(CRONO_DIR) configed-$(CRONO_DIR)

unconfig-$(CRONO_DIR):
	@(rm -f configed-$(CRONO_DIR))

configed-$(CRONO_DIR): $(CRONO_DIR)
	@(echo Configing $(CRONO_DIR)...;\
	  $(CRONO_CONFIGURE_PUSHD);\
	  (($(CRONO_CONFIGURE)) || (exit 1)) && \
	  ((touch $(CRONO_DIR)) || (exit 1)) && \
	  ((touch $(CRONO_MAKEDIR)/configed-$(CRONO_DIR)) || (exit 1));\
	  popd)

########################################################################
# docs
########################################################################

#
# List crono Docs
#
list-crono-docs: $(CRONO_DOCS_TGZ)
	@(echo Listing $(CRONO_DOCS_TGZ)...;\
	  (($(CRONO_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install crono Docs
#
install-crono-docs: $(CRONO_DOCS_PREFIX)
	@(echo Extracting $(CRONO_DOCS_TGZ)...;\
	  (($(CRONO_EXTRACT_DOCS_TGZ)) || (exit 1)))

########################################################################
# patch
########################################################################

#
# List crono Patch
#
list-crono-patch: $(CRONO_PATCH_TGZ)
	@(echo Listing $(CRONO_PATCH_TGZ)...;\
	  (($(CRONO_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract crono patch
#
extract-crono-patch: $(CRONO_DIR)
	@(echo Extracting $(CRONO_PATCH_TGZ)...;\
	  (($(CRONO_EXTRACT_PATCH_TGZ)) || (exit 1)))

########################################################################
# archive
########################################################################

#
# List crono
#
list-crono: 
	@(echo Listing $(CRONO_TGZ)...;\
	  (($(CRONO_LIST_TGZ)) || (exit 1)))

#
# crono extracted
#
crono-extracted: 
	@(echo $(CRONO_EXTRACT) $(CRONO_TGZ))

#
# Extract crono
#
extract-crono: unextract-crono $(CRONO_DIR)

unextract-crono: unconfig-$(CRONO_DIR)
	@(echo Removing $(CRONO_DIR)...;\
	  (($(CRONO_REMOVE_DIR)) || (exit 1)))

$(CRONO_DIR): $(CRONO_TGZ)
	@(echo Extracting $(CRONO_TGZ)...;\
	  (($(CRONO_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(CRONO_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# crono archived
#
crono-archived: 
	@(echo $(CRONO_TGZ))
	  
#
# Archive crono
#
archive-crono: 
	@(echo Archiving $(CRONO_DIR) to $(CRONO_TGZ)...;\
	  (($(CRONO_ARCHIVE) $(CRONO_TGZ) $(CRONO_DIR)) || (exit 1)))

########################################################################
# links
########################################################################

#
# crono linked
#
crono-linked: 
	@echo link is $(CRONO_LINK_NAME) "->" $(CRONO_PREFIX)
	  
#
# Install crono links
#
install-crono-links: 
	@((echo removing $(CRONO_LINK_NAME)) && \
	  ((rm -f $(CRONO_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(CRONO_LINK_NAME) "->" $(CRONO_PREFIX)) && \
	  ((ln -s $(CRONO_PREFIX) $(CRONO_LINK_NAME)) || (exit 1)))
	  
########################################################################
# prefix
########################################################################

#
# crono prefixed
#
crono-prefixed: 
	@((echo prefix is $(CRONO_PREFIX)) && \
	  (echo exec prefix is $(CRONO_EXEC_PREFIX)) && \
	  (echo conf prefix is $(CRONO_CONF_PREFIX)) && \
	  (echo docs prefix is $(CRONO_DOCS_PREFIX)))
	  
#
# Install crono prefix
#
install-crono-prefix: 
	@((echo makeing $(CRONO_PREFIX)) && \
	  ((mkdir -p $(CRONO_PREFIX)) || (exit 1)) && \
	  (echo makeing $(CRONO_EXEC_PREFIX)) && \
	  ((mkdir -p $(CRONO_EXEC_PREFIX)) || (exit 1)))
	  
$(CRONO_PREFIX):
	@(echo Makeing Directory $(CRONO_PREFIX)...;\
	  (($(CRONO_MKDIR) $(CRONO_PREFIX)) || (exit 1)))

$(CRONO_EXEC_PREFIX):
	@(echo Makeing Directory $(CRONO_EXEC_PREFIX)...;\
	  (($(CRONO_MKDIR) $(CRONO_EXEC_PREFIX)) || (exit 1)))

$(CRONO_CONF_PREFIX):
	@(echo Makeing Directory $(CRONO_CONF_PREFIX)...;\
	  (($(CRONO_MKDIR) $(CRONO_CONF_PREFIX)) || (exit 1)))

$(CRONO_DOCS_PREFIX):
	@(echo Makeing Directory $(CRONO_DOCS_PREFIX)...;\
	  (($(CRONO_MKDIR) $(CRONO_DOCS_PREFIX)) || (exit 1)))




        

